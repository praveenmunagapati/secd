#include<stdio.h>


/*
 *      returntype functionaname(pramaters only declarations){
 *          statemetns
 *          return returntype;
 *      }
 **/
// 1 without parameter without return
void wopwor(void) {
    printf("type 1\n");
    return;
}
// 2 with parameter without return
void wpwor(int a) {
    printf("%d\n",a);
    return;
}
// 3 without parameter with return
int wopwr(void) {
    return 5;
}
// with parameter with return
int wpwr(int a,int b) {
    return a+b;
}

int main(void) {
    setbuf(stdout, 0);

    //FUNCTIONS
    wopwor();
    wpwor(15.5);
    int returnvalue = wopwr();
    printf("%d\n",returnvalue);
    int sum = wpwr(8,9);
    printf("%d\n",sum);

    return 0;
}
