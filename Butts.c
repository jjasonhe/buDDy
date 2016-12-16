//Butts.c

#include "simplelink.h"
#include "tm4c123gh6pm.h"
#include "Butts.h"
#include "ADC.h"

int pushButt2;
int pushButt1;
int butt2;
int butt1;
int lcd2 = 1;
int lcdS = 0;
int lcd1 = 0;
int lcdX = 0;
int lcdY = 0;
int lcdZ = 0;
int lcd0 = 0;
int lcdB = 0;
int lcdD = 0;

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

void Butts_Init(void){
  DisableInterrupts();
	SYSCTL_RCGCGPIO_R |= 0x10;  //activate Port E for button triggering
	GPIO_PORTE_DIR_R &= ~0x06;  //make Port E1-2 inputs
	GPIO_PORTE_DEN_R |= 0x06;   //enable digital IO on Port E1-2
}
