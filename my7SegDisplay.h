/*
 * my7SegDisplay.h
 *
 * Created: 1/1/2024 4:12:46 PM
 *  Author: Albert
 */ 

#ifndef MY7SEGDISPLAY_H_
#define MY7SEGDISPLAY_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

extern const unsigned char dispNumbers[16];

void displaySetup();
void useFirstDigit(unsigned char );
void useSecondDigit(unsigned char );
void useThirdDigit(unsigned char );
void useFourthDigit(unsigned char );
void useSecondDot();
void useFourthDot();
void welcomeMessage();
void closeDisplay();

#endif /* MY7SEGDISPLAY_H_ */