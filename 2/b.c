#include "reg51.h"

#define uchar unsigned char;
#define uint unsigned int;
#define NULL 0;
char tab1[]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};

void delay(){
	char i = 110;
	while(i--);
}

char key(){
	if(P2 != 0xff){
		if(P2 == 0xfd){
			return 1;	
		}
		else if(P2 == 0xfe){
			return 2;
		}
	}
	return NULL;
}

void main(){
	char i,status=1;
	while(1){
		status = key();
		if(status == 1){
			for(i = 0;i<7;i++){
				P1 = tab1[i];
				delay();
			}
		}
		else if(status == 2){
			for(i = 8;i>0;i--){
				P1 = tab1[i];	
			}
		}	
	}
}