/*
 * myLED.c
 *
 * Created: 1/2/2024 2:25:27 PM
 *  Author: Albert
 */ 
#include "myLED.h"

void ledSetup() {
	// set PINs 1 - PD1, 8 - PB0 and 13 - PB5 as output low;

	DDRD |= (1 << DDRD1);
	PORTD &= ~(1 << PORTD1);

	DDRB |= (1 << DDRB0);
	PORTB &= ~(1 << PORTB0);

	DDRB |= (1 << DDRB5);
	PORTB &= ~(1 << PORTB5);
}

void turnOnCollisionLED() {
	// PINs 13 (-) and 8 (+);

	DDRD &= ~(1 << DDRD1);
	PORTD &= ~(1 << PORTD1);

	DDRB |= (1 << DDRB0);
	PORTB |= (1 << PORTB0);

	DDRB |= (1 << DDRB5);
	PORTB &= ~(1 << PORTB5);
}

void turnOffCollisionLED() {
	// PINs 13 (-) and 8 (+);

	DDRD &= ~(1 << DDRD1);
	PORTD &= ~(1 << PORTD1);

	DDRB |= (1 << DDRB0);
	PORTB &= ~(1 << PORTB0);

	DDRB |= (1 << DDRB5);
	PORTB &= ~(1 << PORTB5);
}

void turnOnPulseLED() {
	// PINs 13 (+) and 8 (-);

	DDRD &= ~(1 << DDRD1);
	PORTD &= ~(1 << PORTD1);

	DDRB |= (1 << DDRB0);
	PORTB &= ~(1 << PORTB0);

	DDRB |= (1 << DDRB5);
	PORTB |= (1 << PORTB5);
}

void turnOffPulseLED() {
	// PINs 13 (+) and 8 (-);

	DDRD &= ~(1 << DDRD1);
	PORTD &= ~(1 << PORTD1);

	DDRB |= (1 << DDRB0);
	PORTB &= ~(1 << PORTB0);

	DDRB |= (1 << DDRB5);
	PORTB &= ~(1 << PORTB5);
}