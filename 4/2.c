#include "reg51.h"
#define u8 unsigned char;
#define u16 unsigned int;
sbit out = P1^0;
void init_timer(){
    TMOD = 0X02;
    TH0 = 0X38;
    TL0 = 0X38;
    IE = 0X82;
    IP = 0X02;
}
void timer0() interrupt 1{
    out = !out;
}

void main(){
    init_timer();
    while(1);
}