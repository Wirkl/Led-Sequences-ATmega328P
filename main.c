/**************************\
* Led Sequences Program    *
* Micro: Atmega328P        *
* Date: 17-02-2022         *
\**************************/

/********** Macros **********/
#define F_CPU 16000000UL							// 16 MHz clock speed
#define Button_SeqUp (PIND & (1<<PD6))>>PD6			// Sequence Up Button
#define Button_SeqDown (PIND & (1<<PD5))>>PD5		// Sequence Down Button
#define Button_SpeedUp (PIND & (1<<PD0))>>PD0		// Speed Up Button
#define Button_SpeedDown (PIND & (1<<PD1))>>PD1		// Speed Down Button
#define NSequences 20								// Number of Sequences

/********* Librerias *********/
#include <avr/io.h>									//Avr Library
#include <util/delay.h>								//Delay Library

/** Funciones y Subrutinas ***/
void Delayms(int);									// Function to Apply Delays in Sequences
void Sequence1();									// Function of Sequence #1
void Sequence2();									// --------------------	#2
void Sequence3();									// -------------------- #3
void Sequence4();									// -------------------- #4
void Sequence5();									// -------------------- #5
void Sequence6();									// -------------------- #6
void Sequence7();									// -------------------- #7
void Sequence8();									// -------------------- #8
void Sequence9();									// -------------------- #9
void Sequence10();									// -------------------- #10
void Sequence11();									// -------------------- #11
void Sequence12();									// -------------------- #12
void Sequence13();									// -------------------- #13
void Sequence14();									// -------------------- #14
void Sequence15();									// -------------------- #15
void Sequence16();									// -------------------- #16
void Sequence17();									// -------------------- #17
void Sequence18();									// -------------------- #18
void Sequence19();									// -------------------- #19
void Sequence20();									// -------------------- #20
void Read_Sequence();								// Function to Read the Press on Sequence Up or Down Buttons
void Read_Speed();									// Function to Read the Press on Speed Up or Down Change Buttons

//** Definicion de variables globales  ***
int Sequence=1;										
int Time=200;										

/******* Main Function *******/
int main(void)
{
	//**Configuración de Puertos ****

	DDRB |= 0b00111110;								// Set PB1-PB5 as Output
	DDRC |= 0b00111110;								// Set PC1-PC5 as Output
	DDRD |= 0b00000000;								// Set PDX as Input
	
	while(1)										//Infinite Loop
	{
		switch (Sequence)
		{
			case 1:
				Sequence1();
				break;
			case 2:
				Sequence2();
				break;
			case 3:
				Sequence3();
				break;
			case 4:
				Sequence4();
				break;
			case 5:
				Sequence5();
				break;
			case 6:
				Sequence6();
				break;
			case 7:
				Sequence7();
				break;
			case 8:
				Sequence8();
				break;
			case 9:
				Sequence9();
				break;
			case 10:
				Sequence10();
				break;
			case 11:
				Sequence11();
				break;
			case 12:
				Sequence12();
				break;
			case 13:
				Sequence13();
				break;
			case 14:
				Sequence14();
				break;
			case 15:
				Sequence15();
				break;
			case 16:
				Sequence16();
				break;
			case 17:
				Sequence17();
				break;
			case 18:
				Sequence18();
				break;
			case 19:
				Sequence19();
				break;
			case 20:
				Sequence20();
				break;
		}
		Read_Sequence();
		Read_Speed();
		_delay_ms(200);
	}
}

/******* Sequence Delay Function *******/

void Delayms(int n) {
	while(n--) {
		_delay_ms(1);
	}
}

/***** Sequence Up and Down Buttons Read *****/

void Read_Sequence()
{
	if(Button_SeqUp==1)
	{
		if(Sequence<NSequences)
		{
			Sequence++;
		}
	}
	if(Button_SeqDown==1)
	{
		if(Sequence>1)
		{
			Sequence--;
		}
	}
}

/******* Speed Up and Down Buttons Read *******/

void Read_Speed()
{
	if(Button_SpeedUp==1)
	{
		if(Time>50)
		{
			Time = Time - 50;
		}
	}
	if (Time<50) Time = 50;
	
	if(Button_SpeedDown==1)
	{
		if(Time<500)
		{
			Time = Time + 50;
		}
	}
	if (Time>500) Time = 500;
}

/*********** Led Sequences Functions ***********/

void Sequence1()
{
	PORTB = 0x2;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x20;	Delayms(Time);
}

void Sequence2()
{
	PORTB = 0x0;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x0;	Delayms(Time);
}

void Sequence3()
{
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x2;	Delayms(Time);
}

void Sequence4()
{
	PORTB = 0x20;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
}

void Sequence5()
{
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x2;	Delayms(Time);
}

void Sequence6()
{
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x10;	Delayms(Time);
}

void Sequence7()
{
	PORTB = 0x2;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x6;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0xE;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x1E;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x6;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0xE;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x1E;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x3E;	Delayms(Time);
}

void Sequence8()
{
	PORTB = 0x0;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x30;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x38;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x3C;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x30;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x38;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x3C;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x3E;	Delayms(Time);
}

void Sequence9()
{
	PORTB = 0x3C;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x3A;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x36;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x2E;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x1E;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x3C;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x3A;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x36;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x2E;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x1E;	Delayms(Time);
}

void Sequence10()
{
	PORTB = 0x3E;	PORTC = 0x1E;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x2E;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x36;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x3A;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x3C;	Delayms(Time);
	PORTB = 0x1E;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x2E;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x36;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x3A;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x3C;	PORTC = 0x3E;	Delayms(Time);
}

void Sequence11()
{
	PORTB = 0x2;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x2;	Delayms(Time);
}

void Sequence12()
{
	PORTB = 0x20;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x20;	Delayms(Time);
}

void Sequence13()
{
	PORTB = 0x2;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x2;	Delayms(Time);

}

void Sequence14()
{
	PORTB = 0x0;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x2;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x0;	Delayms(Time);

}

void Sequence15()
{
	PORTB = 0x6;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x30;	Delayms(Time);
	PORTB = 0xA;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x28;	Delayms(Time);
	PORTB = 0x12;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x24;	Delayms(Time);
	PORTB = 0x22;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x22;	Delayms(Time);
}

void Sequence16()
{
	PORTB = 0x2;	PORTC = 0x22;	Delayms(Time);
	PORTB = 0x22;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x24;	Delayms(Time);
	PORTB = 0x12;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x28;	Delayms(Time);
	PORTB = 0xA;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x30;	Delayms(Time);
	PORTB = 0x6;	PORTC = 0x20;	Delayms(Time);
}

void Sequence17()
{
	PORTB = 0x24;	PORTC = 0x32;	Delayms(Time);
	PORTB = 0x2A;	PORTC = 0xA;	Delayms(Time);
	PORTB = 0x30;	PORTC = 0x26;	Delayms(Time);
	PORTB = 0x2A;	PORTC = 0xA;	Delayms(Time);
	PORTB = 0x24;	PORTC = 0x32;	Delayms(Time);
	PORTB = 0x32;	PORTC = 0x6;	Delayms(Time);
	PORTB = 0x28;	PORTC = 0x2A;	Delayms(Time);
	PORTB = 0x26;	PORTC = 0x12;	Delayms(Time);
	PORTB = 0x28;	PORTC = 0x2A;	Delayms(Time);
	PORTB = 0x32;	PORTC = 0x6;	Delayms(Time);
}

void Sequence18()
{
	PORTB = 0x32;	PORTC = 0x6;	Delayms(Time);
	PORTB = 0x28;	PORTC = 0x2A;	Delayms(Time);
	PORTB = 0x26;	PORTC = 0x12;	Delayms(Time);
	PORTB = 0x28;	PORTC = 0x2A;	Delayms(Time);
	PORTB = 0x32;	PORTC = 0x6;	Delayms(Time);
	PORTB = 0x24;	PORTC = 0x32;	Delayms(Time);
	PORTB = 0x2A;	PORTC = 0xA;	Delayms(Time);
	PORTB = 0x30;	PORTC = 0x26;	Delayms(Time);
	PORTB = 0x2A;	PORTC = 0xA;	Delayms(Time);
	PORTB = 0x24;	PORTC = 0x32;	Delayms(Time);
}

void Sequence19()
{
	PORTB = 0x0;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x0;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x0;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x2;	PORTC = 0x20;	Delayms(Time);
	PORTB = 0x4;	PORTC = 0x10;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x10;	PORTC = 0x4;	Delayms(Time);
	PORTB = 0x20;	PORTC = 0x2;	Delayms(Time);
}

void Sequence20()
{
	PORTB = 0x3E;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x1C;	PORTC = 0x1C;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x1C;	PORTC = 0x1C;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x3E;	Delayms(Time);
	PORTB = 0x1C;	PORTC = 0x1C;	Delayms(Time);
	PORTB = 0x8;	PORTC = 0x8;	Delayms(Time);
	PORTB = 0x1C;	PORTC = 0x1C;	Delayms(Time);
	PORTB = 0x3E;	PORTC = 0x3E;	Delayms(Time);
}

