#include<stdio.h>
#include "myfunctions/mylib.h"
static int k;

int foo() {
    static int k;
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
    printf("%d\n",k);

    return 0;
}