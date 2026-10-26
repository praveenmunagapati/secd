#include <stdio.h>
void factorial(int i) {
    if (i == 0) {
        return;
    }
    printf("%d\n",i);
    factorial(--i);
    return;
}
int main() {
    setbuf(stdout,0);
    //factorial without recursion
    int num = 5;
    int result = 1;
    for (int i = num ; i > 0; --i) {
        // printf("%d\n",i);
        result*=i;
    }
    printf("%d\n",result);
    factorial(5);
    return 0;
}
