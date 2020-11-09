/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	Demo Link: 
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTB = 0x00;
    
	ADC_init();
	unsigned short x = ADC;
	unsigned char tempB = 0x00;
	unsigned short max = 0;
     /* Insert your solution below */

    while (1) {
	x = ADC;

	if(x > max){
		max = x;
	}


	if(((max * 7) / 8) <= x){
		tempB = 0xFF;
	}
	else if(((max * 6) / 8) <= x){
		tempB = 0x7F;
	}
	else if(((max * 5) / 8) <= x){
		tempB = 0x3F;
	}
	else if(((max * 4) / 8) <= x){
		tempB = 0x1F;
	}
	else if(((max * 3) / 8) <= x){
		tempB = 0x0F;
	}
	else if(((max * 2) / 8) <= x){
		tempB = 0x07;
	}
	else if(((max * 2) / 8) <= x){
		tempB = 0x03;
	}
	else{
		tempB = 0x01;
	}
	PORTB = tempB;
    }
    return 1;
}
