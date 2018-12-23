#include "button.h"
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define SET_BIT(DST, POS, VALUE) DST = (DST & ~(1 << POS)) | (VALUE << POS)
#define GET_BIT(SRC, POS) (SRC & (1 << POS)) >> POS

Button CreateButton(uint8_t pin, void (*onBtnDown)() ,void (*onBtnUp)())
{
	Button button;
	button.Pin = pin;
	button.IsClicked = 0;
	button.OnButtonDown = onBtnDown;
	button.OnButtonUp = onBtnUp;

	//set button's pin in read mode
	SET_BIT(DDRx, (button.Pin), 0);

	//pull-up resistor
	SET_BIT(PORTx, (button.Pin), 1);

	return button;
}

void Poll(Button* button)
{
	_delay_ms(10);//debouncing
	if (~(GET_BIT(PINx, (button->Pin))) && !button->IsClicked)
	{
		button->IsClicked = 1;
		button->OnButtonDown();
	}
	if (GET_BIT(PINx, (button->Pin)) && button->IsClicked)
	{
		button->IsClicked = 0;
		button->OnButtonUp();
	}
}
