#include <stdio.h>
int  factorialr(int i) {
    if (i == 0) {
        return 1 ;
    }
    // for (int i = num ; i > 0; --i) {
    //     // printf("%d\n",i);
    //     result*=i;
    // }

    return i * factorialr(i-1);
}

int factorial(int num) {
    int result = 1;
    for (int i = num ; i > 0; --i) {
        // printf("%d\n",i);
        result*=i;
    }
    return result;
}

int main() {
    setbuf(stdout,0);
    //factorial without recursion
    int result;
    int num = 5;
   printf("%d\n", factorial(num));
   printf("%d\n", factorialr(num));
    return 0;
}
