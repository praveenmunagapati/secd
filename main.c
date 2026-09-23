#include<stdio.h>
#include<math.h>

int main(void) {
    setbuf(stdout, 0);
    //searching in linear array
    int array[10] = {15,78,14,59,3,45,72,9,6,7};
    //swaping
    int a = 15;
    int b = 20;
    printf("before\n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("after\n");
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    printf("without third variable\n");
    a = a*b/(b=a);
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    return 0;
}