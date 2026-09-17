#include<stdio.h>

void printbinary(unsigned int num) {
    for (int i = 128;i!=0;i>>=1) {
        printf("%d",num&i?1:0);
    }
    printf("\n");
    return;
}
int main(void) {
    setbuf(stdout, 0);
    //d) Write a program that shows
    //the binary equivalent of a given positive number between 0 to 255.

    unsigned int num =  179;

    //&
    //10 -> 1010
    // 8  -> 1000
    //10 -> 1010
    // 4   -> 0100
    //10 -> 1010
    // 2   -> 0010
    //10 -> 1010
    // 1  -> 0001
    for (int i = 128;i!=0;i>>=1) {
        printf("%d",num&i?1:0);
    }
    printf("\n");

    printbinary(188);
    printbinary(59);
    printbinary(16);
    printbinary(1);
    printbinary(15);
    return 0;
}