/*
 * myLED.h
 *
 * Created: 1/2/2024 2:25:03 PM
 *  Author: Albert
 */ 


#ifndef MYLED_H_
#define MYLED_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void ledSetup();
void turnOnCollisionLED();
void turnOffCollisionLED();
void turnOnPulseLED();
void turnOffPulseLED();

#endif /* MYLED_H_ */