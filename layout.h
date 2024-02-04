#include "keycodes.h"


#define ROW_COUNT 4
#define COL_COUNT 14
#define LAYOUT_COUNT 4

#define LAYSWITCH1 (ROW_COUNT * 6 + 1)
#define LAYSWITCH2 (ROW_COUNT * 7 + 1)

const char key_codes[ROW_COUNT * COL_COUNT * LAYOUT_COUNT] = {
	// layout 0
	ESC,  TAB,  LCTL, LFSH,
	AD07, AC07, AB01, AC06,
	AD08, AD03, AC09, AD04,
	AD09, AB05, AB04, AB03,
	AD10, AC08, AB06, AD02,
	AD11, AC11, AB07, AB02,
	LWIN, 0,    RTRN, HOME,

	RALT, 0,    SPCE, END,
	AD12, AD05, AB08, AC04,
	AE01, AD01, AB10, AC03,
	AE02, AB09, AC01, AE05,
	AE03, AC05, AC02, AE06,
	AE04, AC06, AE07, AE09,
	BKSP, DELE, AE08, RTSH,

	// layout 1
	FK04, 0, 0,    0,
	FK05, 0, 0,    0,
	FK06, 0, 0,    0,
	FK07, 0, 0,    0,
	FK08, 0, 0,    0,
	FK09, 0, 0,    0,
	0,    0, DELE, 0,

	0,    0, DELE, 0,
	FK10, 0, 0,    0,
	FK11, 0, 0,    0,
	FK12, 0, 0,    0,
	FK01, 0, 0,    0,
	FK02, 0, 0,    0,
	FK03, 0, 0,    0,

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
