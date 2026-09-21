#include<stdio.h>
#include<math.h>
int maxarrayofints(int arrayofints[ ]) {
    int max = 0;
    max = arrayofints[0] ;

    for (int i = 0;i<10;i++) {
        if (max<=arrayofints[i]) {
            max = arrayofints[i];
        }
    }
    arrayofints[9] = 500000;
    return max;
}
int main(void) {
    setbuf(stdout, 0);
    int arrayofints[10];
    arrayofints[0] = 5;
    arrayofints[1] = 6;
    arrayofints[2] = 7;
    arrayofints[3] = 17;
    arrayofints[4] = 46;
    arrayofints[5] = 47;
    arrayofints[6] = 78;
    arrayofints[7] = 89;
    arrayofints[8] = 50;
    arrayofints[9] = 50;
    // int x[ ] = {9,8,7};//compiler automatically calculates sizes allocates memeory



    int max = maxarrayofints(arrayofints);

    printf("max is %d\n",max);
    printf("max is %d\n",arrayofints[9]);
    for (int i = 0;i<10;i++) {
            printf("%d\n",arrayofints[i]);
    }
    printf("%p\n",arrayofints);
    printf("%p\n",&arrayofints[0]);
    for (int i = 0;i<10;i++) {
        printf("%p\n",&arrayofints[i]);
    }
    int *pa = arrayofints;
    printf("%d\n",*pa);
    printf("%d\n",*(pa+1));
    printf("%d\n",*(pa+2));

    for (int i = 0;i<10;i++) {
        printf("%d\n",*(pa+i));
    }
    for (int i = 0;i<10;i++) {
        printf("%p\n",(pa+i));
    }

    for (int i = 0;i<10;i++) {
        printf("%d\n",*(arrayofints+i));//arrays are better pointers
    }
    return 0;
}