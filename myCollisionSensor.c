/*
 * myCollisionSensor.c
 *
 * Created: 1/2/2024 1:18:19 PM
 *  Author: Albert
 */ 

#include "myCollisionSensor.h"

void collisionSensorSetup() {
	// set pin 9 as input, with pull-up resistance;
	DDRB &= ~(1 << DDRB1);
	PORTB |= (1 << PORTB1);

	// enable interrupt on PCINT1;
	PCICR |= (1 << PCIE0);
	PCMSK0 |= (1 << PCINT1);
}

ISR(PCINT0_vect) {
	closeDisplay();
	dht_state = -1;
	
	_delay_ms(350);
	if(PINB & (1 << PINB1)) // verify if the value on PINB1 is HIGH (collision detected)
		turnOnCollisionLED();
}