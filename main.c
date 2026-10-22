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

    int array[5] = {1,2,3,4,5};
    int big = array[0];
    int littlebig = array[1];
    for (int i = 0; i < 5; ++i) {
        if ( big < array[i]) {
            littlebig  = big;
            big = array[i];
        }else if (littlebig!=big && littlebig<array[i] ){
            littlebig  = array[i];
        }

    }
    printf("%d\n",littlebig);




    return 0;
}
