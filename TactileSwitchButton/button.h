/*
* button.h
*
* Created: 23.12.2018 0:48:00
* Author : Alexander Velilyaev
* Contact: Alexandervelilyaev@gmail.com
*
* Library for comfortable work with tactile button switch 
*/

#ifndef BUTTON_H_
#define BUTTON_H_

//replace PORTB, DDRB, PINB if you are using a different port
#define PORTx PORTB
#define DDRx DDRB
#define PINx PINB

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

typedef struct {
	uint8_t IsClicked;//is clicked state
	uint8_t Pin;//number of pin
	void (*OnButtonDown)(void);//on buttonDown event handler
	void (*OnButtonUp)(void);//on buttonUp event handler
} Button;

Button CreateButton(uint8_t pin, void (*onBtnDown)() ,void (*onBtnUp)());

//call this method in while(1) loop
void Poll(Button* button);

#endif /* BUTTON_H_ */