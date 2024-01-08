/*
 * my7SegDisplay.c
 *
 * Created: 1/1/2024 4:13:30 PM
 *  Author: Albert
 */ 

#include "my7SegDisplay.h"

const unsigned char dispNumbers[16] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 57, 118, 124, 28, 84, 92};

void displaySetup() {
	DDRD |= (1 << DDRD7);
	DDRD |= (1 << DDRD6);
	DDRD |= (1 << DDRD5);
	DDRD |= (1 << DDRD4);
	
	DDRB |= (1 << DDRB2);
	DDRB |= (1 << DDRB3);
	DDRB |= (1 << DDRB4);
}

void useFirstDigit(unsigned char number) {
	number = dispNumbers[number];
	
	PORTD &= ~(1 << DDRD7);
	PORTD |= (1 << DDRD6);
	PORTD |= (1 << DDRD5);
	PORTD |= (1 << DDRD4);
	
	// latch low
	PORTB &= ~(1 << DDRB3);
	// shift out the bits MSBFIRST;
	for (char i = 0; i < 8; i++)  {
		if(!!(number & (1 << (7 - i)))) {
			PORTB |= (1 << DDRB4);
			} else {
			PORTB &= ~(1 << DDRB4);
		}
		//generate clock pulse;
		PORTB |= (1 << DDRB2);
		PORTB &= ~(1 << DDRB2);
	}
	// latch high
	PORTB |= (1 << DDRB3);
}


void useSecondDigit(unsigned char number) {
	number = dispNumbers[number];
	
	PORTD |= (1 << DDRD7);
	PORTD &= ~(1 << DDRD6);
	PORTD |= (1 << DDRD5);
	PORTD |= (1 << DDRD4);
	
	// latch low
	PORTB &= ~(1 << DDRB3);
	// shift out the bits MSBFIRST;
	for (char i = 0; i < 8; i++)  {
		if(!!(number & (1 << (7 - i)))) {
			PORTB |= (1 << DDRB4);
			} else {
			PORTB &= ~(1 << DDRB4);
		}
		//generate clock pulse;
		PORTB |= (1 << DDRB2);
		PORTB &= ~(1 << DDRB2);
	}
	// latch high
	PORTB |= (1 << DDRB3);
}

void useThirdDigit(unsigned char number) {
	number = dispNumbers[number];
	
	PORTD |= (1 << DDRD7);
	PORTD |= (1 << DDRD6);
	PORTD &= ~(1 << DDRD5);
	PORTD |= (1 << DDRD4);
	
	// latch low
	PORTB &= ~(1 << DDRB3);
	// shift out the bits MSBFIRST;
	for (char i = 0; i < 8; i++)  {
		if(!!(number & (1 << (7 - i)))) {
			PORTB |= (1 << DDRB4);
			} else {
			PORTB &= ~(1 << DDRB4);
		}
		//generate clock pulse;
		PORTB |= (1 << DDRB2);
		PORTB &= ~(1 << DDRB2);
	}
	// latch high
	PORTB |= (1 << DDRB3);
}

void useFourthDigit(unsigned char number) {
	number = dispNumbers[number];
	
	PORTD |= (1 << DDRD7);
	PORTD |= (1 << DDRD6);
	PORTD |= (1 << DDRD5);
	PORTD &= ~(1 << DDRD4);
	
	// latch low
	PORTB &= ~(1 << DDRB3);
	// shift out the bits MSBFIRST;
	for (char i = 0; i < 8; i++)  {
		if(!!(number & (1 << (7 - i)))) {
			PORTB |= (1 << DDRB4);
			} else {
			PORTB &= ~(1 << DDRB4);
		}
		//generate clock pulse;
		PORTB |= (1 << DDRB2);
		PORTB &= ~(1 << DDRB2);
	}
	// latch high
	PORTB |= (1 << DDRB3);
}

void useSecondDot() {
	PORTD |= (1 << DDRD7);
	PORTD &= ~(1 << DDRD6);
	PORTD |= (1 << DDRD5);
	PORTD |= (1 << DDRD4);

	// latch low
	PORTB &= ~(1 << DDRB3);
	// shift out the bits MSBFIRST;
	for (char i = 0; i < 8; i++)  {
		if(!!(128 & (1 << (7 - i)))) {
			PORTB |= (1 << DDRB4);
			} else {
			PORTB &= ~(1 << DDRB4);
		}
		//generate clock pulse;
		PORTB |= (1 << DDRB2);
		PORTB &= ~(1 << DDRB2);
	}
	// latch high
	PORTB |= (1 << DDRB3);
}

void useFourthDot(){
	PORTD |= (1 << DDRD7);
	PORTD |= (1 << DDRD6);
	PORTD |= (1 << DDRD5);
	PORTD &= ~(1 << DDRD4);

	// latch low
	PORTB &= ~(1 << DDRB3);
	// shift out the bits MSBFIRST;
	for (char i = 0; i < 8; i++)  {
		if(!!(128 & (1 << (7 - i)))) {
			PORTB |= (1 << DDRB4);
			} else {
			PORTB &= ~(1 << DDRB4);
		}
		//generate clock pulse;
		PORTB |= (1 << DDRB2);
		PORTB &= ~(1 << DDRB2);
	}
	// latch high
	PORTB |= (1 << DDRB3);
}

void welcomeMessage(){
	unsigned char i;
	
	for(i = 0; i < 255; i++) {
		useFirstDigit(12);
		_delay_us(1500);
		useSecondDigit(13);
		_delay_us(1500);
		useThirdDigit(14);
		_delay_us(1500);
		useFourthDigit(15);
		_delay_us(1500);
		useFourthDot();
		_delay_us(1500);
	}
}

void closeDisplay() {
	PORTD |= (1 << DDRD7);
	PORTD |= (1 << DDRD6);
	PORTD |= (1 << DDRD5);
	PORTD |= (1 << DDRD4);
}