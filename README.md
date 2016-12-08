# Arduino Wrapper for ATMEGA328P Microcontroller

## About
In one of my side project I have faced with an issue that compiled program is too large
for an Atmega328p microcontroller. This happened because functionality from Arduino
libraries which are written in C++ and very heavy, were used in the project. The decision
was to refuse Arduino libs by writing required functionality in more efficient way for
an Atmega328p.

# Dependencies

Tested on Debian 8.

Install: gcc for avr and avrdude.

```
apt-get install gcc-avr avrdude
```

## Implemented Functionality

##### digitalWrite(pin, state)
##### digitalRead(pin)
##### pinMode(pin, mode)
##### delay(ms)


## Examples
```C
#include "atmega328p.h"

int
main(void)
{
	int state = 0;


	pinMode(13, OUTPUT);

	while (1)
	{
		state ^= 1;
		digitalWrite(13, state);
		delay(500);
	}

	return 0;
}
```
