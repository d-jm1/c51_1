#include "reg51.h"
#define u8 unsigned char
#define u16 unsigned int

sbit clock = P2^4;
sbit ST = P2^5;
sbit EOC = P2^6;
sbit OE = P2^7;
sbit PWM = P3^7;

char ADC,T;

void init_timer(){
	ST = 0;
	EOC = 0;
	OE = 0;
	PWM = 0;
	TMOD = 0X02;
	TH0 = 0X20;
	TL0 = 0X00;
	IE = 0X82;
	TR0 = 1;
}

void timer0() interrupt 1{
	clock = !clock;	
}

void delay(){
	char i = 5;
	while(i--);
}
void read_adc(){
	ST = 1;
	delay();
	ST = 0;
	delay();
	while(!EOC);
	OE = 1;
	delay();
	ADC = P1;
	OE = 0;
	EOC = 0;
}


void main(){
	init_timer();
	while(1){
		read_adc();
		for(T=0X00;T < 0XFF;T++){
			if(T<ADC)
				PWM = 1;
			else
				PWM = 0;	
		}	
	}
}