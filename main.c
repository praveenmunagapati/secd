#include <ctype.h>
#include <stdio.h>
int sumofnatural(int num) {
    int total = 0;
    for (int i = 1; i < 101; ++i) {
        total += i;
    }
    return total;
}
int sumofnaturalr(int num) {
    return num ? num + sumofnaturalr(num - 1 ): 0;
}


int main() {
    setbuf(stdout,0);
    int num = 100;
    int total = 0;
    for (int i = 1; i < 101; ++i) {
        total += i;
    }
    printf("%d\n",total);
    printf("%d\n",sumofnatural(num));
    printf("%d\n",sumofnaturalr(num));

    return 0;
}
