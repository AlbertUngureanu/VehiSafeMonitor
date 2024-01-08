/*
 * myDHT11.c
 *
 * Created: 1/1/2024 4:12:16 PM
 *  Author: Albert
 */ 

#include "myDHT11.h"
#include "my7SegDisplay.h"

unsigned char DHT11[5] = {0};

volatile char dht_state = -1;
volatile unsigned char bitsRead = 0;

ISR(TIMER2_OVF_vect) {
	switch(dht_state) {
		case 0: // first time we enter the OVF event <=> 16.384ms after it has been enabled;
			dht_state = 1;
			TCNT2 = 200;
			break;
		case 1: // second time we enter OVF <=> smth >20ms since enabled;
			dht_state = 2;
			// set PIND2 HIGH
			PORTD |= (1 << PORTD2);
			// now we wait for a response from the sensor;
			// set PIND2 as INPUT;
			DDRD &= ~(1 << DDRD2);

			// wait until response goes low;
			while(PIND & (1 << PIND2));
			// wait until response goes high;
			while((PIND & (1 << PIND2)) == 0);
			// wait until response goes low again so next time it goes high it will be actual data;
			while(PIND & (1 << PIND2));

			// we just triggered and received ok signal from the sensor so now we have to read the information;
			// wait until response goes high;
			while((PIND & (1 << PIND2)) == 0);
			//set prescaler to 8 and counter should start at 176; <=> we need 40us next time;
			TCCR2B = 0;
			TCCR2B |= (1 << CS21);
			TCNT2 = 176;
			break;
		case 2: // we stay in this state while we read the 5 bytes;
				// we know we are 40us later that the time the signal got high;
				// verify if input is still 1 or 0;
		
			if(PIND & (1 << PIND2)) {
				DHT11[bitsRead / 8] = (DHT11[bitsRead / 8] << 1) | (0x01); // add 1 as LSB;
			
				// wait until response goes low;
				while(PIND & (1 << PIND2));
			}
			else {
				DHT11[bitsRead / 8] = (DHT11[bitsRead / 8] << 1); // add 0 as LSB;
			}

			if(bitsRead == 39) { // we read all 5 bytes so we can stop now;
				dht_state = 3;
				TIMSK2 &= ~(1 << TOIE2);
				} else {
				bitsRead++;
			
				// wait until response goes high;
				while((PIND & (1 << PIND2)) == 0);
				TCNT2 = 176;
			}
			break;
		}
}

void requestDataHC11() {
	// set PIND2 as OUTPUT LOW
	DDRD |= (1 << DDRD2);
	PORTD &= ~(1 << PORTD2);

	dht_state = 0;
	bitsRead = 0;
	DHT11[0] = DHT11[1] = DHT11[2] = DHT11[3] = DHT11[4] = 0;
	// enable timer 2 with prescaler 1024; => OVF at 16.384ms;
	TCCR2A = 0;
	TCCR2B = 0;
	TIMSK2 |= (1 << TOIE2);

	//set prescaler to 1024;
	TCCR2B = TCCR2B | (1 << CS22) | (1 << CS21) | (1 << CS20);

	TCNT2 = 0;
}

void displayHumidity() {
	unsigned char i;
	
	for(i = 0; i < 255; i++) {
		useFirstDigit((int)DHT11[0] / 10);
		_delay_us(1500);
		useSecondDigit((int)DHT11[0] % 10);
		_delay_us(1500);
		useSecondDot();
		_delay_us(1500);
		useThirdDigit((int)DHT11[1] % 10);
		_delay_us(1500);
		useFourthDigit(11);
		_delay_us(1500);
	}
}

void displayTemperature() {
	unsigned char i;
	
	for(i = 0; i < 255; i++) {
		useFirstDigit((int)DHT11[2] / 10);
		_delay_us(1500);
		useSecondDigit((int)DHT11[2] % 10);
		_delay_us(1500);
		useSecondDot();
		_delay_us(1500);
		useThirdDigit((int)DHT11[3] % 10);
		_delay_us(1500);
		useFourthDigit(10);
		_delay_us(1500);
	}
}

void displayInfo() {
	requestDataHC11();
	while(dht_state != 3);
	displayHumidity();
	displayTemperature();
			
	dht_state = -1;
}