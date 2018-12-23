# Simple AVR library for Tactile switch button
![banner](https://images-na.ssl-images-amazon.com/images/I/41rmOttqzlL._SX342_.jpg)

### Circuit
![Banner](https://github.com/Alexandervelilyaev/TactileSwitchButton/blob/master/circuit.png?raw=true)


## Methods:

```c 
Button CreateButton(uint8_t pin, void (*onBtnDown)() ,void (*onBtnUp)())
``` 
Create instance of Button. Pass as parameters pin number, pointer to onButtonDownEventHanlder and pointer to onButtonUpEventHanlder

```c
void Poll(Button* button)
``` 
Polling button's state. Call this method in while(1) loop.


## Example:

```c 
#include "Libs/button.h"

void OnButtonUpHandler()
{
  //your code on button up event for button1
}

void OnButtonDownHandler()
{
  //your code on button down event for button1
}

void OnButton2UpHandler()
{
  //your code on button up event for button2
}

void OnButton2DownHandler()
{
  //your code on button down event for button2
}

int main(void)
{
	Button button1= CreateButton(0, &OnButtonDownHandler, &OnButtonUpHandler);
	Button button2 = CreateButton(1, &OnButton2DownHandler, &OnButton2UpHandler);
	while (1)
	{
		Poll(&button1);
		Poll(&button2);
	}
}
``` 
