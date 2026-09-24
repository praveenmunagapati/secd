#include<stdio.h>
int main(void) {
    setbuf(stdout, 0);
    int array2d[2][2] = {{1,2},{3,4}};
    int barray2d[2][2] = {{1,2},{3,4}};
    int rarray2d[2][2] ;
    array2d[0][0] = 5;
    array2d[0][1] = 6;
    array2d[1][0] = 7;
    array2d[1][1] = 9;
    printf("array\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d\t",array2d[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            rarray2d[i][j] = array2d[i][j] + barray2d[i][j];
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d\t",rarray2d[i][j]);
        }
        printf("\n");
    }
    return 0;
}