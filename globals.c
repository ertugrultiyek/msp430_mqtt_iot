/*
 * globals.c
 *
 *  Created on: 3 May 2022
 *      Author: ertugrul.tiyek
 */
#include "globals.h"

void saveState(State *regs){
    regs->control0 = UCB0CTL0;
    regs->control1 = UCB0CTL1;
    regs->br0 = UCB0BR0;
    regs->br1 = UCB0BR1;
    regs->stat = UCB0STAT;
    regs->rx = UCB0RXBUF;
    regs->tx = UCB0TXBUF;
    regs->ie = IE2;
    regs->ifg = IFG2;
}

void loadState(State *regs){
    UCB0CTL0 = regs->control0;
    UCB0CTL1 = regs->control1;
    UCB0BR0 = regs->br0;
    UCB0BR1 = regs->br1;
    UCB0STAT = regs->stat;
    UCB0RXBUF = regs->rx;
    UCB0TXBUF = regs->tx;
    IE2 = regs->ie;
    IFG2 = regs->ifg;
}
