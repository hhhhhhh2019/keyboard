#ifndef UTILS_H
#define UTILS_H


enum PinMode {
	INPUT,
	INPUT_PULLUP,
	OUTPUT
};


void pinMode(char pin, enum PinMode mode);
void pinWrite(char pin, char value);
char pinRead(char pin);


#endif
