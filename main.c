#include<stdio.h>
#include<math.h>
int isinarray(int *parray,int key) {
    int flag = 0;
    for (int i = 0;i<10;i++) {
        if (key == parray[i]) {
            flag = 1;
            break;
        }
    }
    return flag;
}
int main(void) {
    setbuf(stdout, 0);
    //searching in linear array
    int array[10] = {15,78,14,59,3,45,72,9,6,7};
    int key = 45;
    int flag = 0;
    // for (int i = 0;i<10;i++) {
    //     if (key == array[i]) {
    //         flag = 1;
    //         break;
    //     }
    // }

    flag = isinarray(array,key);
    if (flag) {
        printf("key found\n");
    }else {
        printf("key not found\n");
    }
    key = 89;
    flag = isinarray(array,key);
    if (flag) {
        printf("key found\n");
    }else {
        printf("key not found\n");
    }
    

    return 0;
}