#include <ctype.h>
#include <stdio.h>
int arraysum(int *parray) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum+=parray[i];
    }
    return sum;
}
//rigid recursion
int arraysumr(int *parray) {
    if (*parray == 7) {
        return 7;
    }
    return *parray + arraysumr(parray+1) ;
}
int arraysumrf(int *parray,int lenght) {
    if (lenght < 1) {
        return 0;
    }
    return *parray + arraysumrf(parray+1 , lenght -1) ;
}

int main() {
    setbuf(stdout,0);
    int array[5] = {4,6,8,9,7};
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum+=array[i];
    }
    printf("%d\n",sum);
    printf("%p\n",array);
    printf("%d\n",arraysum(array));
    //printf("%d\n",arraysumr(array));
    int *parray = array;
    printf("%p\n",array);
    printf("%p\n",parray);
    printf("%d\n",*parray++);
    printf("%d\n",*parray++);
    printf("%d\n",*parray++);
    printf("%d\n",*parray++);
    printf("%d\n",*parray);
    printf("%d\n",arraysumr(array));
    printf("%d\n",arraysumrf(array,sizeof(array)/sizeof(int)));





    return 0;
}
