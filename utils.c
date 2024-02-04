#include "utils.h"
#include <avr/io.h>


void pinMode(char pin, enum PinMode mode) {
	if (0 <= pin && pin <= 7) {
		if (mode == INPUT) {
			DDRD &= ~(1 << pin);
			PORTD &= ~(1 << pin);
		}

		else if (mode == INPUT_PULLUP) {
			DDRD &= ~(1 << pin);
			PORTD |= 1 << pin;
		}

		else {
			DDRD |= 1 << pin;
			PORTD &= ~(1 << pin);
		}
	}

	else if (8 <= pin && pin <= 14) {
		pin -= 8;

		if (pin == 14 - 8)
			pin++;

		if (mode == INPUT) {
			DDRB &= ~(1 << pin);
			PORTB &= ~(1 << pin);
		}

		else if (mode == INPUT_PULLUP) {
			DDRB &= ~(1 << pin);
			PORTB |= 1 << pin;
		}

		else {
			DDRB |= 1 << pin;
			PORTB &= ~(1 << pin);
		}
	}

	else if (15 <= pin && pin <= 16) {
		pin -= 15;
		pin += 2;

		if (mode == INPUT) {
			DDRA &= ~(1 << pin);
			PORTA &= ~(1 << pin);
		}

		else if (mode == INPUT_PULLUP) {
			DDRA &= ~(1 << pin);
			PORTA |= 1 << pin;
		}

		else {
			DDRA |= 1 << pin;
			PORTA &= ~(1 << pin);
		}
	}

	else if (17 <= pin && pin <= 18) {
		pin -= 17;

		if (mode == INPUT) {
			DDRA &= ~(1 << pin);
			PORTA &= ~(1 << pin);
		}

		else if (mode == INPUT_PULLUP) {
			DDRA &= ~(1 << pin);
			PORTA |= 1 << pin;
		}

		else {
			DDRA |= 1 << pin;
			PORTA &= ~(1 << pin);
		}
	}

	else if (19 <= pin && pin <= 25) {
		pin -= 19;

		if (mode == INPUT) {
			DDRC &= ~(1 << pin);
			PORTC &= ~(1 << pin);
		}

		else if (mode == INPUT_PULLUP) {
			DDRC &= ~(1 << pin);
			PORTC |= 1 << pin;
		}

		else {
			DDRC |= 1 << pin;
			PORTC &= ~(1 << pin);
		}
	}
}


void pinWrite(char pin, char value) {
	char PORT;


	if (0 <= pin && pin <= 7) {
		PORTD = (PORTD & ~(1 << pin)) | (value << pin);
	}

	else if (8 <= pin && pin <= 14) {
		if (pin == 14)
			pin++;

		pin -= 8;
		PORTB = (PORTB & ~(1 << pin)) | (value << pin);
	}

	else if (15 <= pin && pin <= 16) {
		pin -= 15;
		pin += 2;

		PORTA = (PORTA & ~(1 << pin)) | (value << pin);
	}

	else if (17 <= pin && pin <= 18) {
		pin -= 17;

		PORTA = (PORTA & ~(1 << pin)) | (value << pin);
	}

	else if (19 <= pin && pin <= 25) {
		pin -= 19;

		PORTC = (PORTC & ~(1 << pin)) | (value << pin);
	}
}


char pinRead(char pin) {
	char PIN;


	if (0 <= pin && pin <= 7) {
		return (PIND >> pin) & 1;
	}

	else if (8 <= pin && pin <= 14) {
		if (pin == 14)
			pin++;

		pin -= 8;

		return (PINB >> pin) & 1;
	}

	else if (15 <= pin && pin <= 16) {
		pin -= 15;
		pin += 2;

		return (PINA >> pin) & 1;
	}

	else if (17 <= pin && pin <= 18) {
		pin -= 17;

		return (PINA >> pin) & 1;
	}

	else if (19 <= pin && pin <= 25) {
		pin -= 19;

		return (PINC >> pin) & 1;
	}

	return -1;
}
