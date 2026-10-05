#include<stdio.h>
#include "myfunctions/mylib.h"
static int k;

int foo() {
    printf("%d\n",k);
    k++;
    return k;
}

int main(void) {
    setbuf(stdout, 0);
    //storage classes
    //static    → "Create me once; keep me alive."
    //extern    → "I am defined somewhere else.
    printf("%d\n",foo());
    printf("%d\n",foo());
    printf("%d\n",foo());
    // printf("%d\n",k);
    // externalfun();//out of scope
    // staticfoo();
    static int array[10];
    for (int i = 0; i < 10; ++i) {
        printf("%d\t",array[i]);
    }
    return 0;
}