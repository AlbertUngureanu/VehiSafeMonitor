/*
 * myIRsensor.c
 *
 * Created: 1/2/2024 1:39:30 PM
 *  Author: Albert
 */ 

#include "myIRsensor.h"

void presenceSensorSetup() {
	// set pin 3 as input, no pull-up resistance;
	DDRD &= ~(1 << DDRD3);
	PORTD &= ~(1 << PORTD3);

	// enable interrupt on PCINT19;
	PCICR |= (1 << PCIE2);
	PCMSK2 |= (1 << PCINT19);
}

ISR(PCINT2_vect) {
	closeDisplay();
	dht_state = -1;
		
	_delay_ms(900);

	if(!(PIND & (1 << PIND3))) // verify if the value on PIND3 is LOW (hand detected)
		turnOffCollisionLED();
}