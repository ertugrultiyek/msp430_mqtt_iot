#include "globals.h"

#include <stdint.h>
#include <string.h>
#include "ws2812.h"
#include "SSD1306.h"

unsigned char btnPos = 0;
State spi, i2c;


int main(void) {
    WDTCTL = WDTPW + WDTHOLD;  // Stop WDT
    if (CALBC1_16MHZ==0xFF)    // If calibration constant erased
    {
        while(1);              // do not load, trap CPU!!
    }

    // configure clock to 16 MHz
    BCSCTL1 = CALBC1_16MHZ;    // DCO = 16 MHz
    DCOCTL = CALDCO_16MHZ;

    // initialize LED strip
    initStrip();  // ***** HAVE YOU SET YOUR NUM_LEDS DEFINE IN WS2812.H? ******
    saveState(&spi);

    // show the strip
    showStrip();

    // initialize port1
    P1DIR = BIT0;
    P1REN |= (BIT3 | BIT4);
    P1OUT |= (BIT3 | BIT4);
    P1IES |= (BIT3 | BIT4);
    P1IFG = 0;
    P1IE = BIT3 | BIT4;

    P1OUT  &= ~BIT0;
    P1DIR |= BIT0;


    i2c_start();                                // initialize I2C to use with OLED
    saveState(&i2c);

    oled_start();                               // Initialize SSD1306 OLED
    oled_clear();                               // Clear OLED display

    _enable_interrupts();
    // gradually fill for ever and ever
//    LPM1;
    while (1) {
        display_data();
    }
}

//------------------------------Interrupt Vectors--------------------------------------\\__



#pragma vector = PORT1_VECTOR
__interrupt void button(void){

    if((P1IFG & BIT3) == BIT3){
        btnPos ^= BIT4;
        P1IFG &= ~BIT4;
        P1IES ^= BIT4;
        if((btnPos & BIT4) == BIT4)
            display_members();
    }
    else if((P1IFG & BIT4) == BIT4){
        btnPos ^= BIT3;
        P1OUT ^= BIT0;
        P1IFG &= ~BIT3;
        P1IES ^= BIT3;
        if((btnPos & BIT3) == BIT3){
            saveState(&i2c);
            loadState(&spi);
            pixel_show();
        }else{
            saveState(&spi);
            loadState(&i2c);
        }
    }
}

