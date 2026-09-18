#include<stdio.h>
#include<math.h>
//call by reference
void modp(int *px) {
    *px = 15*15;
}
int main(void) {
    setbuf(stdout, 0);
    int x = 10;
    modp(&x);
    printf("%d",x);
    return 0;
}