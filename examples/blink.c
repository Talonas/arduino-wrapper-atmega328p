#include "atmega328p.h"

#define PIN_LED 13

int
main(void)
{
	static int mode = 0;

	pinMode(PIN_LED, OUTPUT);

	while (1)
	{
		mode ^= 1;
		digitalWrite(PIN_LED, mode);
		delay(1000);
	}

	return 0;
}
