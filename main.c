#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)
     

/************************************
 * #include directives...
 ************************************/
#include "LEDarray.h"
#include <xc.h>
#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz

void main(void) 
{
	unsigned int count=0b000000001;
    LEDarray_init();
    int a = 1;
    while (count<0b100000000) 
    {
		
		LEDarray_disp_bin(count); //output a on the LED array in binary
		__delay_ms(300); // Delay so human eye can see change
        count = count <<1; // increment count
        
    } 
    while (count>0b000000001) 
    {
		
		LEDarray_disp_bin(count); //output a on the LED array in binary
		__delay_ms(300); // Delay so human eye can see change
        count = count >>1; // increment count
        
        
    } 
}
