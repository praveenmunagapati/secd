#include<stdio.h>
#include "myfunctions/mylib.h"
int k;//entire program scope default extenal scope not static ie file sccope
int foo() {
    k++;
    return k;
}
int main(void) {
    setbuf(stdout, 0);
    //storage classes
    //extern    → "I am defined somewhere else.
    // printf("%d\n",k);
    // printf("%d\n",foo());
    // printf("%d\n",foo());
    // printf("%d\n",foo());
    // printf("%d\n",k);
    // testextern();
    // printf("%d\n",k);
    //Write a program that calculates
    //the sum of all even numbers between
    //1 and 100 using a for loop.
    //Explain your logic.
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        if (i%2==0) {
            sum+=i;
        }
    }
    printf("%d\n",sum);
    sum = 0;
    for (int i = 1; i <= 100; i++) {
        if (i%2==1) {
            sum+=i;
        }
    }
    printf("%d\n",sum);
    int n = 100;
    n = (n*(n+1))/2;
    printf("%d\n",n);
    printf("%d\n",n/2);
    return 0;
}