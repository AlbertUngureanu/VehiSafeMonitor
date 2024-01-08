/*
 * myIRsensor.h
 *
 * Created: 1/2/2024 1:39:07 PM
 *  Author: Albert
 */ 


#ifndef MYIRSENSOR_H_
#define MYIRSENSOR_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "myLED.h"
#include "my7SegDisplay.h"
#include "myDHT11.h"

void presenceSensorSetup();

#endif /* MYIRSENSOR_H_ */