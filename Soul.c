//Soul.c

#include "simplelink.h"
#include "tm4c123gh6pm.h"
#include "Soul.h"

void Soul_Unlk(void) {
  GPIO_PORTB_DATA_R |= 0x08;
}

void Soul_Lock(void) {
  GPIO_PORTB_DATA_R &= ~0x08;
}

void Soul_Init(void) {
  SYSCTL_RCGCGPIO_R |= 0x02;
  while((SYSCTL_PRGPIO_R&0x02) != 0x02){};
  GPIO_PORTB_DIR_R |= 0x08;       // 2) make PB3 input
  GPIO_PORTB_AFSEL_R &= ~0x08;    // 3) disable alternate function on PB3
  GPIO_PORTB_DEN_R |= 0x08;       // 4) enable digital I/O on PB3
  GPIO_PORTB_AMSEL_R &= ~0x08;    // 5) disable analog functionality on PB3
  Soul_Lock();
}
