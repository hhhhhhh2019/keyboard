#include "keycodes.h"


#define ROW_COUNT 4
#define COL_COUNT 14
#define LAYOUT_COUNT 4

#define LAYSWITCH1 (ROW_COUNT * 6 + 1)
#define LAYSWITCH2 (ROW_COUNT * 7 + 1)

const char key_codes[ROW_COUNT * COL_COUNT * LAYOUT_COUNT] = {
	// layout 0
	ESC,  TAB,  LCTL, LFSH,
	AD06, AB01, AC01, AC11,
	AD07, AB02, AC02, AD01,
	AD08, AB03, AC03, AD02,
	AD09, AB04, AC04, AD03,
	AD10, AB05, AC05, AD04,
	LWIN, 0,    RTRN, HOME,

	RALT, 0,    SPCE, END,
	AD11, AB06, AC06, AD05,
	AD12, AB07, AC07, 0,
	AE01, AB08, AC08, 0,
	AE02, AB09, AC09, 0,
	AE03, AB10, AC10, 0,
	BKSP, DELE, AE08, RTSH,

	// layout 1
	0, 0, 0,    0,
	0, 0, 0,    0,
	0, 0, 0,    0,
	0, 0, 0,    0,
	0, 0, 0,    0,
	0, 0, 0,    0,
	0, 0, DELE, 0,

	0, 0, DELE, 0,
	0, 0, 0,    0,
	0, 0, 0,    0,
	0, 0, 0,    0,
	0, 0, 0,    0,
	0, 0, 0,    0,
	0, 0, 0,    0,

	// layout 2
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,

	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,

	// layout 3
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,

	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
};


char key_states[ROW_COUNT * COL_COUNT];
char key_updated[ROW_COUNT * COL_COUNT];
