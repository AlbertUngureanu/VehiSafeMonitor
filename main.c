/*
 * NXP_FINAL_PROJECT.c
 *
 * Created: 1/1/2024 4:10:03 PM
 * Author : Albert
 */ 

#include "myCollisionSensor.h"
#include "myIRsensor.h"
#include "my7SegDisplay.h"
#include "myDHT11.h"

int main(void)
{
	SREG |= (1 << 7);
		
	displaySetup();
	collisionSensorSetup();
	presenceSensorSetup();
	ledSetup();
	
	welcomeMessage();
	
    while (1) 
    {
		displayInfo();
    }
}