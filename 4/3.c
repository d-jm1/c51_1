#include "reg51.h"
#define u8 unsigned char;
#define u16 unsigned int;
sbit out = P1^0;
void init_timer(){
    TMOD = 0x01;
}
void mian(){
    init_timer();
    while(1){
        TH0 = 0XFF;
        TL0 = 0X38;
        TR0 = 2;
        while(TF0 = 0);
        TF0 = 0;
        out = !out;
    }
}