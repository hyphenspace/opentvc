#include "../driver/time.h"


/** @defgroup group3 TinyTime Library
 *  This library contains a micros function used for timing events.
 *  @{
 */

volatile unsigned long timer0_overflow_count = 0;
volatile unsigned long timer0_millis = 0;

static unsigned char timer0_fract = 0;
volatile unsigned long m;
volatile unsigned long f;


ISR(TIMER0_OVF_vect) {
    m = timer0_millis;
	f = timer0_fract;
	m += MILLIS_INC;
	f += FRACT_INC;
	if (f >= FRACT_MAX) {
		f -= FRACT_MAX;
		m += 1;
	}
	timer0_fract = f;
	timer0_millis = m;
    timer0_overflow_count++;
}

/** Initailzes registors needed for micros function.*/
void init_micros(void) {
	sei();
	TCCR0A |= ((1 << WGM00) | (1 << WGM01));
	TCCR0B |= ((1 << CS00) | (1 << CS01));
	TIMSK0 |= (1 << TOIE0);
}

/** Returns the number of microseconds since the Arduino board began running the current program. This number will overflow (go back to zero), after approximately 70 minutes. */
unsigned long micros(void) {

	unsigned long m;
	unsigned char oldSREG = SREG, t;

	cli();
	m = timer0_overflow_count;
	t = TCNT0;

	if((TIFR0 & (1 << TOV0)) && (t < 255)) {
		m++;
	}
	SREG = oldSREG;

	return ((m << 8) + t) * (64 / clockCyclesPerMicrosecond());
}

/** @} */ // end of group3
