#include<stdio.h>
#include "myfunctions/mylib.h"
int main(void) {
    setbuf(stdout, 0);
    printbinary(188);
    printf("%f",simpleinterest(10000,16,2.6));
    return 0;
}