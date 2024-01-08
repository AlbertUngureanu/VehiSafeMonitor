/*
 * myCollisionSensor.h
 *
 * Created: 1/2/2024 1:17:50 PM
 *  Author: Albert
 */ 


#ifndef MYCOLLISIONSENSOR_H_
#define MYCOLLISIONSENSOR_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "myLED.h"
#include "my7SegDisplay.h"
#include "myDHT11.h"

void collisionSensorSetup();

#endif /* MYCOLLISIONSENSOR_H_ */