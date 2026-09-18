//
// Created by sir on 18-09-2026.
//
#include <stdio.h>
void printbinary(unsigned int num) {
    for (int i = 128;i!=0;i>>=1) {
        printf("%d",num&i?1:0);
    }
    printf("\n");
    return;
}
float simpleinterest(unsigned int principle,unsigned int time,float rate) {
    float si  = (principle * time * rate) / 100;
    return si;
}