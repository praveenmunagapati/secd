#include<stdio.h>
float simpleinterest(unsigned int principle,unsigned int time,float rate) {
    float si  = (principle * time * rate) / 100;
    return si;
}
int main(void) {
    setbuf(stdout, 0);
    //b) Write the program for the simple interest
    //si ptr/100
    unsigned int principle = 100000;
    unsigned int time = 15;
    float rate = 2.5;
    float si  = simpleinterest(principle,time,rate);
    printf("%f\n",si);
    si  = simpleinterest(principle,12,rate);
    printf("%f\n",si);
    si  = simpleinterest(principle,time,rate);
    printf("%f\n",si);
    si  = simpleinterest(principle,time,1.97);
    printf("%f\n",si);
    si  = simpleinterest(1566000,time,rate);
    printf("%f\n",si);
    si  = simpleinterest(principle,89,rate);
    printf("%f\n",si);


    return 0;
}
