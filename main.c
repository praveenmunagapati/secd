#include<stdio.h>
int main(void) {
    setbuf(stdout, 0);
    //a) Write a program for finding the max and min from the three numbers.
    int a =15,b = 15,c=150,max = 0,min = 0;
    if (a>=b && a>=c) {
        max = a;
    }
    if (b>=a && b>=c) {
        max = b;
    }
    if (c>=a && c>=b) {
        max = c;
    }
    printf("%d\n",max);

    return 0;
}
