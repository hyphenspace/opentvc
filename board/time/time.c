#include "../driver/time.h"

volatile unsigned long timer_millis;

ISR(TIMER1_COMPA_vect) {
	timer_millis++;
}

void init_millis(unsigned long f_cpu) {
	unsigned long ctc_overflow_match;
	ctc_overflow_match = ((f_cpu / 1000) / 8);
	TCCR1B |= ((1 << WGM12) | (1 << CS11));
	TIMSK1 |= (1 << OCIE1A);
	OCR1AH = (ctc_overflow_match >> 8);
	OCR1AL = ctc_overflow_match;
}

unsigned long millis(void) {
	unsigned long millis_count;

	ATOMIC_BLOCK(ATOMIC_FORCEON) {
		millis_count = timer_millis;
	}
	return millis_count;
}
