#include<stdio.h>
#define PI 3.14
int main(void) {
    setbuf(stdout,0);
    //logical operators
    //and &&
    // return 1 if both statements are true
    // or ||
    // logical not !

    int a = 100;
    int b = 15;
    int c = 600;
    printf("is a big %d\n",a>b&&a>c);
    printf("%d\n",a>b||a>c);
    printf("%d\n",!0);


return 0;
}