#include "reg51.h"
#define u8 unsigned char;
#define u16 unsigned int;

sbit out = P1^0;

void init_timer(){
    TMOD = 0x01;
    TH0 = 0xFF;
    TL0 = 0x38;
    IE = 0x82;
    IP = 0X02;
}

void timer0() interrupt 1{
    out = !out;
    TH0 = 0XFF;
    TL0 = 0X38;
}

void main(){
    init_timer();
    while(1);
}