#include<stdio.h>
#define PI 3.14
int main(void) {
    setbuf(stdout,0);
    //realational operators
    // = ,
    // assigment operator
    int a = 10;
    int b = 4,c = 50,d = 56;
    a += 1;
    //a = a + 1;
    printf("%d\n",a);
    a -= 1;
    //a = a - 1;
    printf("%d\n",a);
    a*=1;
    //a = a * 1;
    printf("%d\n",a);
    a/=1;
    //a = a / 1;
    printf("%d\n",a);
    a%=1;
    //a = a & 1;
    printf("%d\n",a);


return 0;
}