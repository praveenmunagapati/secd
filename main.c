#include<stdio.h>
#define PI 3.14
int main(void) {
    setbuf(stdout,0);
    //b) Write the program for the simple, compound interest.
    // si = (p*t*r)/100
    float principle;
    float time;
    float rate;
    float simpleinterest ;
    //arthematic
    // + - / * %
    //binary
    // varible [+|-|/|*|%] variable
    // +
    int a = 10;
    int b = 5;
    int c = 6;
    int d = 60;
    int sum = a + d + b + c;
    // 10 + 60  = 70 + 5  75 + 6  81
    //printf("%d",sum);
    int divide = a - b - c - d;
    // printf("%d",divide);
    int mix = a - b + c - d;
    printf("%d\n",mix);
    int mul = a*b;
    printf("%d\n",mul);
    //        365
    //          5
    //                     360
    int mixm = a - b + c * d;
    printf("%d\n",mixm);
    float div = 19/9;// int/int -> int
    printf("%f\n",div);
    //(typecasting)
    unsigned short s;
    unsigned int i =  100000; //short -> int implisit
    s = i;

    float f = i;
    i = (int)2.5;

    printf("%u\n",i);
    char ch = (char)97;
    printf("%c\n",ch);
     a = 1;
     b = 5;
     c = 6;
     d = 10;
    int mixd = a - b / 5 + c * d;
    printf("%d\n",mixd);
    // mod
    //%
    int di = 5/2;
    int m = 5%5;
    printf("%d\n",di);
    printf("%d\n",m);

   // inc dec ++ --
    //++variable unary operator

    //preinc ++variable
    int  x = 10;
    int y ;
    y = ++x;
    // x = x + 1 -> y = x;
    printf("%d\n",x);
    printf("%d\n",y);
    //predec --variable
     x = 10;
    y = --x;
    // x = x - 1 -> y = x;
    printf("%d\n",x);
    printf("%d\n",y);

  //postinc
 //variable++

 int fi = 10;
 int pi = fi++;
 // pi = fi; -> fi = fi + 1
 printf("%d\n",fi);
 printf("%d\n",pi);

 int pd;
 pd = fi--;
 // pd = fi; -> fi = fi - 1
 printf("%d\n",fi);
 printf("%d\n",pd);
return 0;
}