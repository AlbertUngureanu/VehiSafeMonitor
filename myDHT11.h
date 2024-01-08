/*
 * myDHT11.h
 *
 * Created: 1/1/2024 4:10:58 PM
 *  Author: Albert
 */ 

#ifndef MYDHT11_H_
#define MYDHT11_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

extern unsigned char DHT11[5];
extern volatile char dht_state;
extern volatile unsigned char bitsRead;

void requestDataHC11();
void displayHumidity();
void displayTemperature();
void displayInfo();

#endif /* MYDHT11_H_ */