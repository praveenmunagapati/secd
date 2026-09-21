#include<stdio.h>
#include<math.h>

int main(void) {
    setbuf(stdout, 0);
    //biggest 10 number
    /*int num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,max;
    num1 = 1;
    num2 = 5;
    num3 = 6;
    num4 = 2;
    num5 = 9;
    num6 = 15;
    num7 = 8;
    num8 = 12;
    num9 = 45;
    num10 = 150;
   if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num1;
    }
    if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num1;
    }

    if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num1;
    }    if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num1;
    }
    if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num1;
    }
    if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num1;
    }
    if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num1;
    }
    if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num1;
    }
    if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num1;
    }
    if (num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2&&num1>=num2) {
        max = num10;
    }*/
    // char arrayofchars[10];
    // printf("%d\n",sizeof(arrayofchars));
    // float arrayoffloats[10];
    // printf("%d\n",sizeof(arrayoffloats));
    int arrayofints[10];
    //printf("%d\n",sizeof(arrayofints));
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
    //a[10] = 50;
    //
    printf("%d\n",arrayofints[8]);
    printf("%d\n",sizeof(arrayofints[0]));

    int var = 0;
    while (var<10) {
        printf("%d\n",arrayofints[var]);
        var = var + 1;
    }
    printf("%d\n",sizeof(arrayofints[-4]));//uncheked bounds
    printf("%d\n",sizeof(arrayofints[40]));//uncheked bounds
    int max = 0;
    max = arrayofints[0] ;

    for (int i = 0;i<10;i++) {
        if (max<=arrayofints[i]) {
            max = arrayofints[i];
        }
    }
    printf("max is %d\n",max);




    return 0;
}