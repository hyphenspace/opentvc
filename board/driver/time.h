#ifndef TIME_H
#define TIME_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>


// the prescaler is set so that timer0 ticks every 64 clock cycles, and the
// the overflow handler is called every 256 ticks.
#define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(64 * 256))
// the whole number of milliseconds per timer0 overflow
#define MILLIS_INC (MICROSECONDS_PER_TIMER0_OVERFLOW / 1000)

// the fractional number of milliseconds per timer0 overflow. we shift right
// by three to fit these numbers into a byte. (for the clock speeds we care
// about - 8 and 16 MHz - this doesn't lose precision.)
#define FRACT_INC ((MICROSECONDS_PER_TIMER0_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)
#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )

volatile unsigned long timer0_overflow_count = 0;
volatile unsigned long timer0_millis = 0;

static unsigned char timer0_fract = 0;
volatile unsigned long m;
volatile unsigned long f;

void init_micros(void);
unsigned long micros(void);

#endif // TIME_H
