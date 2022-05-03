#include "SSD1306.h"
#include "font_5x7.h"

// data

unsigned char *PTxData;        // Pointer to TX data                                                  // Pointer to TX data
unsigned char TxByteCtr;       // number of bytes to TX

//////////////
          const  unsigned char tx1[]={0x40,0,0,0,0,0,0,0,0,0,0,128,192,224,240,240,240,112,56,56,24,24,24,152,136,136,204,204,204,204,204,204,204,204,196,228,230,230,230,230,230,230,230,230,230,230,230,230,226,242,242,243,243,243,243,243,243,243,243,243,243,243,243,243,243,243,243,243,243,243,115,115,243,243,243,243,243,243,243,242,242,242,242,226,230,230,230,230,230,230,230,230,230,230,228,228,196,204,204,204,204,204,204,204,200,200,152,24,24,24,24,56,120,240,240,240,224,192,128,0,0,0,0,0,0,0,0,0,0};

          const  unsigned char tx2[]={0x40,0,0,0,0,0,192,224,248,252,255,255,127,31,7,3,1,128,224,248,252,254,255,255,255,255,255,255,255,255,255,255,191,191,191,159,159,159,159,159,223,223,207,207,143,143,143,15,15,7,7,7,7,7,3,3,3,195,195,227,241,241,241,249,249,252,252,252,252,254,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,252,240,224,128,1,3,15,63,127,255,255,252,248,224,128,0,0,0,0,0};

          const  unsigned char tx3[]={0x40,0,0,224,252,255,255,255,255,31,7,1,0,0,224,248,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,15,1,0,0,0,0,0,128,240,252,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,240,192,0,0,1,7,63,255,255,255,254,248,192,0,0};

          const  unsigned char tx4[]={0x40,192,255,255,255,255,255,255,1,0,0,0,0,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,248,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,252,128,0,0,0,1,255,255,255,255,255,254,0};


          const  unsigned char tx5[]={0x40,7,255,255,255,255,255,255,192,0,0,0,0,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,128,0,0,0,0,0,0,7,227,227,227,227,227,243,241,241,241,241,241,241,241,241,241,241,241,241,241,241,241,241,241,241,241,241,225,225,227,227,227,227,195,7,7,7,7,15,15,15,223,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,15,0,0,0,128,255,255,255,255,255,255,0};

          const  unsigned char tx6[]={0x40,0,0,7,63,255,255,255,255,252,224,0,0,0,7,63,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,252,240,192,128,0,0,0,15,63,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,31,7,3,0,0,192,224,240,252,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,63,15,1,0,0,192,240,255,255,255,255,127,31,3,0};

          const  unsigned char tx7[]={0x40,0,0,0,0,0,3,15,31,127,255,255,252,248,224,192,0,3,7,31,63,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,252,240,224,192,129,7,31,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,63,15,3,129,192,224,248,252,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127,31,15,3,0,128,224,240,252,255,255,127,63,15,3,1,0,0,0,0};

          const  unsigned char tx8[]={0x40,0,0,0,0,0,0,0,0,0,0,1,3,7,15,31,31,30,28,24,24,24,49,51,51,51,51,51,51,51,35,39,103,103,103,103,103,103,103,103,103,103,103,103,103,111,207,207,207,207,207,207,207,207,207,207,206,206,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,206,206,207,207,207,207,79,79,79,79,103,103,103,103,103,103,103,103,103,103,103,103,103,39,39,51,51,51,51,51,51,49,48,16,24,28,30,31,31,15,15,7,3,0,0,0,0,0,0,0,0,0,0};
         /////
          const  unsigned char p1[]={0x40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,192,192,224,224,224,224,224,224,192};

          const  unsigned char p2[]={0x40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,192,192,224,224,240,240,240,248,248,120,124,60,60,62,30,30,30,30,15,15,15,15,15,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,15,15,15,15,15,14,30,30,30,30,62,60,60,60,124,120,120,120,120,124,124,62,62,31,31,15,15,15,7,7,3,3,1,1,0,0};

          const  unsigned char p3[]={0x40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,224,224,240,248,252,254,254,127,63,31,15,7,7,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,192,192,224,224,224,240,240,240,240,120,120,120,120,120,56,56,56,60,60,60,60,60,60,60,60,56,56,56,120,120,120,120,120,120,240,240,240,240,224,224,224,192,192,192,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

          const  unsigned char p4[]={0x40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,240,248,252,254,255,255,255,255,255,255,63,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,240,248,252,254,255,255,63,31,15,7,3,3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,192,192,192,192,128,128,128,0,0,0,0,0,0,1,1,1,3,3,7,7,15,31,63,63,254,254,252,248,248,240,224,192,0,0,0,0,0};

          const  unsigned char p5[]={0x40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,224,240,248,252,254,255,255,127,63,15,7,31,127,255,255,255,255,255,248,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,31,63,127,255,255,255,252,240,224,192,192,128,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,129,193,195,227,255,255,255,255,255,127,62,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,255,255,255,255,255,255,252,0,0,0};

          const  unsigned char p6[]={0x40,0,0,0,0,0,128,128,192,192,224,240,240,248,252,254,127,63,63,31,15,7,7,3,1,0,0,0,0,0,0,0,1,7,15,31,63,127,255,255,252,248,240,224,192,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,3,3,7,7,7,7,7,7,15,15,15,15,15,15,15,15,15,15,15,15,7,7,7,7,7,3,3,3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,128,192,224,240,252,255,255,255,127,63,31,15,1,0,0,0};

          const  unsigned char p7[]={0x40,12,28,30,31,31,63,63,63,63,127,123,121,121,120,240,240,240,240,240,224,224,224,224,224,224,224,192,192,192,192,192,192,192,192,192,128,128,128,129,129,131,135,135,143,143,159,159,158,190,188,188,252,248,248,248,240,240,240,224,224,224,224,224,192,192,192,192,192,192,192,128,128,128,128,128,128,128,128,128,128,128,128,128,128,192,192,192,192,192,192,192,192,224,224,224,224,224,224,240,240,240,240,120,120,120,124,60,62,62,31,31,31,15,15,7,7,3,1,1,0,0,0,0,0,0,0,0,0};

          const  unsigned char p8[]={0x40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

          const  unsigned char fire1[]={0x40,0,0,0,0,128,128,240,252,248,240,224,128,0,0,0,0};
          const  unsigned char fire2[]={0x40,0,0,0,60,71,3,131,7,0,129,67,127,63,0,0,0};

          const  unsigned char cold1[]={0x40,0,16,112,120,120,192,68,63,63,68,192,120,120,112,16,0};
          const  unsigned char cold2[]={0x40,0,8,14,30,30,3,34,252,252,34,3,30,30,14,8,0};


          const  unsigned char c1[]={0x40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
          const  unsigned char c2[]={0x40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

          const unsigned char wifi1[]={0x40,112,56,156,206,230,119,51,179,179,51,119,230,206,156,56,112};
          const unsigned char wifi2[]={0x40,0,0,1,1,14,7,99,243,243,99,7,14,1,1,0,0};

          const unsigned char wifi3[]={0x40,24,12,38,146,219,73,73,219,146,38,12,24};
          const unsigned char wifi4[]={0x40,0,0,0,0,4,14,14,4,0,0,0,0};


//////////////



void i2c_start(void){
    P1SEL    |= SCL + SDA;                                              // Assign I2C pins to USCI_B0
    P1SEL2   |= SCL + SDA;                                              // Assign I2C pins to USCI_B0
    UCB0CTL1 |= UCSWRST;                                                // Enable SW reset
    UCB0CTL0  = UCMST + UCMODE_3 + UCSYNC;                              // I2C Master, synchronous mode
    UCB0CTL1  = UCSSEL_2 + UCSWRST;                                     // Use SMCLK, keep SW reset
    UCB0BR0   = 10;                                                     // fSCL = SMCLK/10 = ~100kHz with SMCLK = 1MHz
    UCB0BR1   = 0;
    UCB0CTL1 &= ~UCSWRST;                                               // Clear SW reset, resume operation
    IE2      |= UCB0TXIE;                                               // Enable TX interrupt
}

void i2c_datatransfer(unsigned char slave_address, unsigned char *DataBuffer, unsigned char ByteCtr) {
    UCB0I2CSA = slave_address;
P1IE &= ~BIT3;
    PTxData = DataBuffer;
    TxByteCtr = ByteCtr;

    while (UCB0CTL1 & UCTXSTP);                                         // Ensure stop condition got sent
    UCB0CTL1 |= UCTR + UCTXSTT;                                         // I2C TX, start condition
    while (UCB0CTL1 & UCTXSTP);                                         // Ensure stop condition got sent
P1IE |= BIT3;

        __bis_SR_register(CPUOFF + GIE);              // Enter LPM0 w/ interrupts
                                                     // Remain in LPM0 until all data is TX'd
}

// setting of screen

void oled_command(unsigned char command) {
    buffer[0] = 0x80;
    buffer[1] = command;

    i2c_datatransfer(SSD1306_I2C_ADDRESS, buffer, 2);
} // end oled_command

void oled_clear(void) {

    oled_position(0, 0);
    uint8_t i;
    for (i = 64; i > 0; i--) {                                          // count down for loops when possible for ULP
        uint8_t x;
        for(x = 16; x > 0; x--) {
            if (x == 1) {
                buffer[x-1] = 0x40;
            } else {
                buffer[x-1] = 0x0;
            }
        }


        i2c_datatransfer(SSD1306_I2C_ADDRESS, buffer, 17);

    }
} // end oled_clear


void oled_TextPrintBlock(uint8_t x, uint8_t y, char *ptString) {
    char word[12];
    uint8_t i;
    uint8_t endX = x;
    while (*ptString != '\0'){
        i = 0;
        while ((*ptString != ' ') && (*ptString != '\0')) {
            word[i] = *ptString;
            ptString++;
            i++;
            endX += 6;
        }

        word[i++] = '\0';

        if (endX >= 127) {
            x = 0;
            y++;
            oled_TextPrint(x, y, word);
            endX = (i * 6);
            x = endX;
        } else {
            oled_TextPrint(x, y, word);
            endX += 6;
            x = endX;
        }
        ptString++;
    }

}

void oled_position(uint8_t column, uint8_t page) {
    if (column > 128) {
        column = 0;                                                     // constrain column to upper limit
    }

    if (page > 8) {
        page = 0;                                                       // constrain page to upper limit
    }

    oled_command(SSD1306_COLUMNADDR);
    oled_command(column);                                            // Column start address (0 = reset)
    oled_command(SSD1306_LCDWIDTH-1);                                // Column end address (127 = reset)

    oled_command(SSD1306_PAGEADDR);
    oled_command(page);                                              // Page start address (0 = reset)
    oled_command(7);                                                 // Page end address
} // end oled_position


void oled_TextPrint(uint8_t x, uint8_t y, char *ptString) {
    oled_position(x, y);

    while (*ptString != '\0') {
        buffer[0] = 0x40;

        if ((x + 5) >= 127) {                                           // char will run off screen
            x = 0;                                                      // set column to 0
            y++;                                                        // jump to next page
            oled_position(x, y);                                  // send position change to oled
        }

        uint8_t i;
        for(i = 0; i< 5; i++) {
            buffer[i+1] = font_5x7[*ptString - ' '][i];
        }

        buffer[6] = 0x0;

        i2c_datatransfer(SSD1306_I2C_ADDRESS, buffer, 7);
        ptString++;
        x+=6;
    }
} // end oled_TextPrint



void oled_start(void) {
    // SSD1306 init sequence
    oled_command(SSD1306_DISPLAYOFF);                                // 0xAE
    oled_command(SSD1306_SETDISPLAYCLOCKDIV);                        // 0xD5
    oled_command(SSD1306_SETLOWCOLUMN);
    oled_command(0x21);
    oled_command(0x80);                                              // the suggested ratio 0x80
    oled_command(SSD1306_SETLOWCOLUMN);
    oled_command(SSD1306_SETMULTIPLEX);                              // 0xA8
    oled_command(SSD1306_LCDHEIGHT - 1);
    oled_command(0x21);
    oled_command(SSD1306_SETDISPLAYOFFSET);                          // 0xD3
    oled_command(0x0);                                               // no offset
    oled_command(SSD1306_SETSTARTLINE | 0x0);                        // line #0
    oled_command(SSD1306_CHARGEPUMP);                                // 0x8D
    oled_command(0x14);                                              // generate high voltage from 3.3v line internally
    oled_command(SSD1306_MEMORYMODE);                                // 0x20
    oled_command(0x00);                                              // 0x0 act like ks0108
    oled_command(SSD1306_SEGREMAP | 0x1);
    oled_command(SSD1306_COMSCANDEC);

    oled_command(SSD1306_SETCOMPINS);                                // 0xDA
    oled_command(0x12);
    oled_command(SSD1306_SETCONTRAST);                               // 0x81
    oled_command(0xCF);

    oled_command(SSD1306_SETPRECHARGE);                              // 0xd9
    oled_command(0xF1);
    oled_command(SSD1306_SETVCOMDETECT);                             // 0xDB
    oled_command(0x40);
    oled_command(SSD1306_DISPLAYALLON_RESUME);                       // 0xA4
    oled_command(SSD1306_NORMALDISPLAY);                             // 0xA6

    oled_command(SSD1306_DEACTIVATE_SCROLL);


    oled_command(SSD1306_DISPLAYON);                                 //--turn on oled panel
} // end oled_start


void display_data(){
    char txtBlock3[93] = "Clock:";
    oled_TextPrintBlock(0, 2, txtBlock3);

    char txtBlock[93] = "Temperature:";
    oled_TextPrintBlock(0, 4, txtBlock);

    char txtBlock2[93] = "Humadity:";
    oled_TextPrintBlock(0, 6, txtBlock2);

     oled_position(108,1);
     i2c_datatransfer(SSD1306_I2C_ADDRESS, wifi3,13);

     oled_position(108,2);
     i2c_datatransfer(SSD1306_I2C_ADDRESS, wifi4,13);

     for(n=51;n<59;n++){



      char txtBlock6[10] = {n,':',n,n,':',n,n};
      char txtBlock5[10] = {n,n,n};
      oled_TextPrint(53, 2, txtBlock6);
      oled_TextPrint(77, 4, txtBlock5);
      oled_TextPrint(77, 6, txtBlock5);


      oled_position(108,3);
      i2c_datatransfer(SSD1306_I2C_ADDRESS, fire1,17);
      oled_position(108,4);
      i2c_datatransfer(SSD1306_I2C_ADDRESS, fire2,17);
      SHORT_DELAY;


      oled_position(108,3);
      i2c_datatransfer(SSD1306_I2C_ADDRESS, c1,17);
      oled_position(108,4);
      i2c_datatransfer(SSD1306_I2C_ADDRESS, c2,17);



      oled_position(108,3);
      i2c_datatransfer(SSD1306_I2C_ADDRESS, cold1,17);
      oled_position(108,4);
      i2c_datatransfer(SSD1306_I2C_ADDRESS, cold2,17);
      SHORT_DELAY;



      oled_position(108,3);
      i2c_datatransfer(SSD1306_I2C_ADDRESS, c1,17);  //clear
      oled_position(108,4);
      i2c_datatransfer(SSD1306_I2C_ADDRESS, c2,17);  //clear


      SHORT_DELAY;

     }

   SHORT_DELAY;
}

void display_members(){
    oled_clear();
    char txtBlock3[93] = "Project Members";
    oled_TextPrintBlock(0, 1, txtBlock3);

    char txtBlock4[93] = "Omer Kocer";
    oled_TextPrintBlock(0, 3, txtBlock4);
    char txtBlock5[93] = "Faruk Ates";
    oled_TextPrintBlock(0, 4, txtBlock5);
    char txtBlock6[93] = "Ertugrul Tiyek";
    oled_TextPrintBlock(0, 5, txtBlock6);
    LONG_DELAY;
}

void display_logo(){
    i2c_datatransfer(SSD1306_I2C_ADDRESS, tx1,129);  //hacettepe logo
    i2c_datatransfer(SSD1306_I2C_ADDRESS, tx2,129);
    i2c_datatransfer(SSD1306_I2C_ADDRESS, tx3,129);
    i2c_datatransfer(SSD1306_I2C_ADDRESS, tx4,129);
    i2c_datatransfer(SSD1306_I2C_ADDRESS, tx5,129);
    i2c_datatransfer(SSD1306_I2C_ADDRESS, tx6,129);
    i2c_datatransfer(SSD1306_I2C_ADDRESS, tx7,129);
    i2c_datatransfer(SSD1306_I2C_ADDRESS, tx8,129);
    LONG_DELAY;
}

#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCIAB0TX_ISR(void) {
    if (TxByteCtr) {                                                    // Check TX byte counter
        UCB0TXBUF = *PTxData++;                                         // Load TX buffer
        TxByteCtr--;                                                    // Decrement TX byte counter
    } else {
        UCB0CTL1 |= UCTXSTP;                                            // I2C stop condition
        IFG2 &= ~UCB0TXIFG;                                             // Clear USCI_B0 TX int flag
        __bic_SR_register_on_exit(CPUOFF);                              // Exit LPM0
  }
}
