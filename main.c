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
	unsigned int count=0;
    LEDarray_init();
    
while(1)
{
    while (!PORTFbits.RF2)//empty while loop (wait for button press)
    {
        __delay_ms(500);//wait 500ms for press
        count+=10;//increment count
        LEDarray_disp_dec(count); //output a on the LED array in decimal 
        __delay_ms(50); // Delay so human eye can see change
        while(!PORTFbits.RF2)//instant response
        {
            count+=10;//increment count 
            if (count>110) 
            {
                count=0;
            } //reset a when it gets too big
            LEDarray_disp_dec(count); //output a on the LED array in binary
            __delay_ms(50); // Delay so human eye can see change
            
        }
    }
}

}
