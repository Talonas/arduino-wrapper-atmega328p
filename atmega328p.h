#ifndef INCLUDE_WcEgrdD0FoPTNrgn9oxPwlos4s5IZlH7
#define INCLUDE_WcEgrdD0FoPTNrgn9oxPwlos4s5IZlH7 1

#include <util/delay.h>
#include <avr/io.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0


/**
 * Writes HIGH or LOW value to pin.
 * @param[in] pin Number of pin to write.
 * @param[in] state HIGH or LOW.
 */
#define digitalWrite(pin, state) _DIGITAL_WRITE(pin, state);

/**
 * Reads the value from a specified pin.
 * @param[in] pin Number of pin to read.
 * @return HIGH or LOW
 */
#define digitalRead(pin) _DIGITAL_READ(pin);

/**
 * Configures pin to behave as an input or an output.
 * @param[in] pin Number of pin to be configured.
 * @param[in] mode INPUT or OUTPUT.
 */
#define pinMode(pin, mode) _PIN_MODE(pin, mode);

/**
 * Delays the program for the amount of time in milliseconds.
 * @param[in] ms Amount of time to sleep (ms).
 */
#define delay(ms) _DELAY(ms);


#define _DIGITAL_WRITE(pin, state) _DIGITAL_WRITE__ ## pin(state);
/* PD related */
#define _DIGITAL_WRITE__0(state) DIGITAL_WRITE(PORTD, PD0, state);
#define _DIGITAL_WRITE__1(state) DIGITAL_WRITE(PORTD, PD1, state);
#define _DIGITAL_WRITE__2(state) DIGITAL_WRITE(PORTD, PD2, state);
#define _DIGITAL_WRITE__3(state) DIGITAL_WRITE(PORTD, PD3, state);
#define _DIGITAL_WRITE__4(state) DIGITAL_WRITE(PORTD, PD4, state);
#define _DIGITAL_WRITE__5(state) DIGITAL_WRITE(PORTD, PD5, state);
#define _DIGITAL_WRITE__6(state) DIGITAL_WRITE(PORTD, PD6, state);
#define _DIGITAL_WRITE__7(state) DIGITAL_WRITE(PORTD, PD7, state);
/* PB related */
#define _DIGITAL_WRITE__8(state) DIGITAL_WRITE(PORTB, PB0, state);
#define _DIGITAL_WRITE__9(state) DIGITAL_WRITE(PORTB, PB1, state);
#define _DIGITAL_WRITE__10(state) DIGITAL_WRITE(PORTB, PB2, state);
#define _DIGITAL_WRITE__11(state) DIGITAL_WRITE(PORTB, PB3, state);
#define _DIGITAL_WRITE__12(state) DIGITAL_WRITE(PORTB, PB4, state);
#define _DIGITAL_WRITE__13(state) DIGITAL_WRITE(PORTB, PB5, state);


#define _DIGITAL_READ(pin) _DIGITAL_READ__ ## pin();
/* PD related */
#define _DIGITAL_READ__0() DIGITAL_READ(PIND, PD0);
#define _DIGITAL_READ__1() DIGITAL_READ(PIND, PD1);
#define _DIGITAL_READ__2() DIGITAL_READ(PIND, PD2);
#define _DIGITAL_READ__3() DIGITAL_READ(PIND, PD3);
#define _DIGITAL_READ__4() DIGITAL_READ(PIND, PD4);
#define _DIGITAL_READ__5() DIGITAL_READ(PIND, PD5);
#define _DIGITAL_READ__6() DIGITAL_READ(PIND, PD6);
#define _DIGITAL_READ__7() DIGITAL_READ(PIND, PD7);
/* PB related */
#define _DIGITAL_READ__8() DIGITAL_READ(PINB, PB0);
#define _DIGITAL_READ__9() DIGITAL_READ(PINB, PB1);
#define _DIGITAL_READ__10() DIGITAL_READ(PINB, PB2);
#define _DIGITAL_READ__11() DIGITAL_READ(PINB, PB3);
#define _DIGITAL_READ__12() DIGITAL_READ(PINB, PB4);
#define _DIGITAL_READ__13() DIGITAL_READ(PINB, PB5);


#define _PIN_MODE(pin, mode) _PIN_MODE__ ## pin(mode);
/* DDRD related */
#define _PIN_MODE__0(mode) PIN_MODE(DDRD, DDD0, mode);
#define _PIN_MODE__1(mode) PIN_MODE(DDRD, DDD1, mode);
#define _PIN_MODE__2(mode) PIN_MODE(DDRD, DDD2, mode);
#define _PIN_MODE__3(mode) PIN_MODE(DDRD, DDD3, mode);
#define _PIN_MODE__4(mode) PIN_MODE(DDRD, DDD4, mode);
#define _PIN_MODE__5(mode) PIN_MODE(DDRD, DDD5, mode);
#define _PIN_MODE__6(mode) PIN_MODE(DDRD, DDD6, mode);
#define _PIN_MODE__7(mode) PIN_MODE(DDRD, DDD7, mode);
/* DDRB related */
#define _PIN_MODE__8(mode) PIN_MODE(DDRB, DDB0, mode);
#define _PIN_MODE__9(mode) PIN_MODE(DDRB, DDB1, mode);
#define _PIN_MODE__10(mode) PIN_MODE(DDRB, DDB2, mode);
#define _PIN_MODE__11(mode) PIN_MODE(DDRB, DDB3, mode);
#define _PIN_MODE__12(mode) PIN_MODE(DDRB, DDB4, mode);
#define _PIN_MODE__13(mode) PIN_MODE(DDRB, DDB5, mode);


#define _DELAY(ms) \
({ \
	unsigned int delay = ms; \
	while (delay--) \
	{ \
		_delay_ms(1); \
	} \
})


#define DIGITAL_WRITE(reg, port, state) \
({ \
	if (state == HIGH) \
	{ \
		reg |= _BV(port); \
	} \
	else \
	{ \
		reg &= ~_BV(port); \
	} \
})


#define DIGITAL_READ(reg, pin) \
({ \
	uint8_t retval = LOW; \
	if (reg & _BV(pin)) \
	{ \
		retval = HIGH; \
	} \
	retval; \
})


#define PIN_MODE(reg, port, mode) \
({ \
	if (mode == OUTPUT) \
	{ \
		reg |= _BV(port); \
	} \
	else \
	{ \
		reg &= ~_BV(port); \
	} \
})

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_WcEgrdD0FoPTNrgn9oxPwlos4s5IZlH7 */
