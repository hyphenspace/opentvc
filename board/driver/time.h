#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

void init_millis(unsigned long f_cpu);
unsigned long millis(void);
