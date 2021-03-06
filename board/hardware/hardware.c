#include "../driver/hardware.h"

/** @defgroup group6 Hardware Library
 *  This library contains all the neccessary code for on board status indications.
 *  @{
 */


/** This function initialize the registors used for the RGB LED.*/
void initStatusLED(void) {
  DDRC |= ((1 << DDC0) |(1 << DDC1) | (1 << DDC2) );
}

/** This function blinks the BLUE LED. */
void blueStatusLED(void) {
  LED_PORT |= (1 << BLUE_LED);
  _delay_ms(500);
  LED_PORT &= ~(1 << BLUE_LED);
  _delay_ms(250);
}

/** This function blinks the RED LED. */
void redStatusLED(void) {
  LED_PORT |= (1 << RED_LED);
  _delay_ms(500);
  LED_PORT &= ~(1 << RED_LED);
  _delay_ms(250);
}

/** This function blinks the GREEN LED. */
void greenStatusLED(void) {
  LED_PORT |= (1 << GREEN_LED);
  _delay_ms(500);
  LED_PORT &= ~(1 << GREEN_LED);
  _delay_ms(250);
}

/** @} */ // end of group2