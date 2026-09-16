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

    int c = 20;

    if (a>b) {
        if (a>c) {
            printf("a is big");
        }
    }
    if (b>a) {//b>a  && b>c
        if (b>c) {
            printf("b is big\n");
        }
    }
    if (c>a) {
        if (c>b) {
            printf("c is big\n");
        }
    }
    a = 15;
    b = 20;
    if (a>b) {
        printf("a is big\n");
    }else {
        printf("b is big\n");
    }
    //else
    //else if ladder
    a = 15;
    b = 20;
    c = 16;
    if (a > b && a > c) {
        printf("a is big\n");
    } else if (b > a && b > c) {
        printf("b is big\n");
    } else if (c > a && c > b) {
        printf("c is big\n");
    }
    // ?:
    a = 15;
    b = 20;
    printf(a>b?"a is big":"b is big\n");

    //switch
    // case
    //break
    //default
    a = 15;
    b = 20;
    char choice = 'r';
    switch(choice) {
        case '+' : printf("%d + %d =  %d\n",a,b,a+b);break;
        case '-' : printf("%d - %d =  %d\n",a,b,a-b);break;
        case '*' : printf("%d * %d =  %d\n",a,b,a*b);break;
        case '/' : printf("%d / %d =  %f\n",a,b,(float)a/b);break;
        case '%' : printf("%d mod %d =  %d\n",a,b,a%b);break;

            default:printf("no ops");break;
    }

    return 0;
}
