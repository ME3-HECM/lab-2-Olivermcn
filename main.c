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
	ADC_init();
    LEDarray_init();
    unsigned int LDR;
    int oldLDRval = 0;
    while(1)
    {
        LDR = ADC_getval(); //get ADC voltage reference value
        if (LDR>100){LDR = 100;}
        while (oldLDRval>LDR)
        {
            LDR = ADC_getval(); //get new ADC voltage reference value
            
            LEDarray_disp_PPM(oldLDRval, LDR);
            oldLDRval = oldLDRval - 10;
            __delay_ms(1000);
        }
        LEDarray_disp_upto(LDR);//display everything up to LDR value
        oldLDRval = LDR;
        __delay_ms(200);
        
    }   
}