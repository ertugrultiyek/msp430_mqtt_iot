/*
 * includes.h
 *
 *  Created on: 3 May 2022
 *      Author: ertugrul.tiyek
 */
#include <msp430.h>


typedef struct state{
    unsigned char control0;
    unsigned char control1;
    unsigned char br0;
    unsigned char br1;
    unsigned char stat;
    unsigned char rx;
    unsigned char tx;
    unsigned char ie;
    unsigned char ifg;
} State;


void saveState(State *regs);
void loadState(State *regs);

