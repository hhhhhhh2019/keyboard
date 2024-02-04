#include <avr/pgmspace.h>
#include "keycodes.h"
#include "usbdrv.h"

#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "layout.h"
#include "utils.h"


const uint8_t configurationReply[8] = {
	0,0,0,0,0,0,0
};

const char usbHidReportDescriptor[USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH] = {
	0x05, 0x01,       // Usage Page (Generic Desktop),
  0x09, 0x06,       // Usage (Keyboard),
  0xA1, 0x01,       // Collection (Application),
  0x05, 0x07,       // Usage Page (Key Codes),
  0x19, 0xE0,       // Usage Minimum (224),
  0x29, 0xE7,       // Usage Maximum (231),
  0x15, 0x00,       // Logical Minimum (0),
  0x25, 0x01,       // Logical Maximum (1),
  0x75, 0x01,       // Report Size (1),
  0x95, 0x08,       // Report Count (8),
  0x81, 0x02,       // Input (Data, Variable, Absolute), ;Modifier byte

  0x95, 0x01,       // Report Count (1),
  0x75, 0x08,       // Report Size (8),
  0x81, 0x01,       // Input (Constant),                 ;Reserved byte

  0x95, 0x06,       // Report Count (6),
  0x75, 0x08,       // Report Size (8),
  0x15, 0x00,       // Logical Minimum (0),
  0x25, 0xff,       // Logical Maximum (255),
  0x05, 0x07,       // Usage Page (Key Codes),
  0x19, 0x00,       // Usage Minimum (0),
  0x29, 0xff,       // Usage Maximum (255),
  0x81, 0x00,       // Input (Data, Array),               ;Key arrays (6 bytes)

  0xC0
};

typedef struct {
	uint8_t modifier;
	uint8_t reserved;
	uint8_t keycode[6];
} report_t;

static report_t reportBuffer;
static uchar    idleRate;


char updated_keys = 0;

void read_keys();
void update();


usbMsgLen_t usbFunctionSetup(uchar data[8]) {
	usbRequest_t *rq = (void*) data;

	if ((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS) {
		if (rq->bRequest == USBRQ_HID_GET_REPORT) {
			usbMsgPtr = (void*)&reportBuffer;
			return sizeof(reportBuffer);
		}

		else if (rq->bRequest == USBRQ_HID_GET_IDLE) {
			usbMsgPtr = &idleRate;
			return 1;
		}

		else if (rq->bRequest == USBRQ_HID_SET_IDLE) {
			idleRate = rq->wValue.bytes[1];
		}
	}

	return 0;
}


int main() {
	for (int i = 3; i <= 6; i++)
		pinMode(i, INPUT_PULLUP);

	for (int i = 8; i <= 21; i++) {
		pinMode(i, OUTPUT);
		pinWrite(i, 1);
	}


	wdt_reset();
	MCUSR  =  0;
	WDTCSR |= _BV(WDCE) | _BV(WDE);
	WDTCSR =  0;


	usbInit();

	usbDeviceDisconnect();
	for (int i = 0; i < 500; i++) {
		wdt_reset();
		_delay_ms(1);
	}
	usbDeviceConnect();

	sei();

	for (;;) {
		wdt_reset();
		usbPoll();


		read_keys();

		if (usbInterruptIsReady() && updated_keys != 0) {
			update();
			usbSetInterrupt((void*)&reportBuffer, sizeof(reportBuffer));
		}
	}
}



void read_keys() {
	updated_keys = 0;


	for (int i = 0; i < COL_COUNT; i++) {
		pinWrite(i + 8, 0);

		for (int j = 0; j < ROW_COUNT; j++) {
			char key = !pinRead(j + 3);
			char id = j + i * ROW_COUNT;

			key_updated[id] = key_states[id] != key;
			updated_keys += key_updated[id];

			key_states[id] = key;
		}

		pinWrite(i + 8, 1);
	}
}


void update() {
	for (int i = 0; i < 6; i++)
		reportBuffer.keycode[i] = 0;
	reportBuffer.modifier = 0;


	char layout_id = key_states[LAYSWITCH1] | (key_states[LAYSWITCH2] << 1);

	char bid = 0;

	for (int i = 0; i < ROW_COUNT * COL_COUNT; i++) {
		if (key_codes[i] == LFSH) {
			reportBuffer.modifier |= MOD_SHIFT_LEFT;
			continue;
		}

		if (key_codes[i] == RTSH) {
			reportBuffer.modifier |= MOD_SHIFT_RIGHT;
			continue;
		}

		if (key_codes[i] == LCTL) {
			reportBuffer.modifier |= MOD_CONTROL_LEFT;
			continue;
		}

		if (key_codes[i] == RCTL) {
			reportBuffer.modifier |= MOD_CONTROL_RIGHT;
			continue;
		}

		if (key_codes[i] == LALT) {
			reportBuffer.modifier |= MOD_ALT_LEFT;
			continue;
		}

		if (key_codes[i] == RALT) {
			reportBuffer.modifier |= MOD_ALT_RIGHT;
			continue;
		}

		if (key_codes[i] == LWIN) {
			reportBuffer.modifier |= MOD_GUI_LEFT;
			continue;
		}

		if (key_codes[i] == RWIN) {
			reportBuffer.modifier |= MOD_GUI_RIGHT;
			continue;
		}

		if (key_states[i] == 0)
			continue;

		reportBuffer.keycode[bid++] = key_codes[i + layout_id * ROW_COUNT * COL_COUNT];
	}
}
