#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)
     

/************************************
 * #include directives...
 ************************************/
#include "LEDarray.h"
#include "ADC.h"
#include <xc.h>
#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz

void main(void) 
{
    int a = 0;
	ADC_init();
    LEDarray_init();
    unsigned int LDR;
    while(1)
    {
    LDR = ADC_getval(); //get ADC voltage refrence value
    LEDarray_disp_upto(LDR); //display LDR value
    __delay_ms(500);
    }   
}