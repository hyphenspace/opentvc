#include "unity/unity.h"

#define DEFAULT_PULSE_WIDTH 3050
#define MIN_PULSE_WIDTH 1350
#define MAX_PULSE_WIDTH	4750

void setUp(void){}
void tearDown(void){}

signed long map(signed long angle, unsigned long in_min, unsigned long in_max, unsigned long out_min, unsigned long out_max) {
	  static signed int value = 0;
	    value = (angle - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	      return value;
}


void test_map(void) {
	TEST_ASSERT_EQUAL_INT(DEFAULT_PULSE_WIDTH, map(0, -90, 90, 1350, 4750));
	TEST_ASSERT_EQUAL_INT(MIN_PULSE_WIDTH, map(-90, -90, 90, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH));
	TEST_ASSERT_EQUAL_INT(MAX_PULSE_WIDTH, map(90, -90, 90, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH));
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_map);
	return UNITY_END();
}
