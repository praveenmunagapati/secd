#include<stdio.h>
int main(void)
{
    setbuf(stdout,0);
    //slection statements
    //if else switch case default break
    int a = 10;
    int b = 15;
    int result = a>b;
    if (result){
        printf("a is big");
    }
    result = b>a;
    if (result) {
        printf("b is big");
    }

    if (-7) {
        printf("praneetha");
    }
    return 0;
}
