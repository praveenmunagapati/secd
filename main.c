#include<stdio.h>
int main(void) {
    setbuf(stdout, 0);
    int array2d[2][2] = {{1,2},{3,4}};
    int *parray2d[2];
    parray2d[0] =  array2d[0];
    parray2d[1] =  array2d[1];
    printf("%p\n", array2d[0]);
    printf("%p\n", array2d[1]);
    printf("%p\n",parray2d[0]);
    printf("%p\n",parray2d[1]);
    printf("%d\n",parray2d[0][0]);
    printf("%d\n",parray2d[0][1]);
    printf("%d\n",parray2d[1][0]);
    printf("%d\n",parray2d[1][1]);
    int (*pforarray2d)[2] = array2d;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d\n",pforarray2d[i][j]);
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d\n",*(*(pforarray2d + i) + j));
        }
    }
    int array[5] = {4,5,6,1,2};
    for (int i = 0; i < 5; ++i) {
        printf("%d \t",array[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d \t",i[array]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d \t",*(array +i));
    }
    printf("%d \t",array[4]);
    printf("%d \t",4[array]);

    return 0;
}