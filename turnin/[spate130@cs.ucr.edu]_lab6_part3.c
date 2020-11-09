/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	Demo Link: https://youtu.be/OQkp7Hcy3vY
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}


// max = 571
// min = 63

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTB = 0x00;
    
	ADC_init();
	unsigned short x = ADC;
	unsigned char tempB = 0x00;
	unsigned short max = 200;
     /* Insert your solution below */


    while (1) {
	x = ADC;

	if (x >= max/2){
		tempB = 0x01;
	}
	else{
		tempB = 0x00;
	}

	PORTB = tempB;
    }
    return 1;
}
