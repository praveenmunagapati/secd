#include <stdio.h>
int main() {
    setbuf(stdout,0);
    // 2. Medium
    // Write a C program to find the second-largest element in an array
    // without sorting the array.
    // use cases
    // 2
    // 10 20 30 40 50
    // 40
    // 1
    // 12 5 8 25 15 20
    // 20

    int array[5] = {18 ,201, 530, 320, 50};

    int max = array[0];
    for (int i = 0; i < 5; ++i) {
        if (max<array[i]) {
            max = array[i];
        }
    }
    printf("%d\n",max);
    int diff = max;

    for (int i = 0; i < 5; ++i) {
        if (diff == array[i]) {
            continue;
        }
        if (diff > max-array[i]) {
            diff = array[i];
        }
    }
    printf("%d\n",diff);



    return 0;
}
