#include<stdio.h>
#include<math.h>
void bubblesort(int *array) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (array[i]<array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return;
}
int main(void) {
    setbuf(stdout, 0);
    //searching in linear array
    int array[10] = {15,78,14,59,3,45,72,9,6,7};

    printf("\nbefore sorting\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d\t",array[i]);
    }
    bubblesort(array);
    printf("\nafter sorting\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d\t",array[i]);
    }

    int array1[10] = {15,78,14,8,3,74,72,9,6,7};
    printf("\nbefore sorting\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d\t",array1[i]);
    }
    bubblesort(array1);
    printf("\nafter sorting\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d\t",array1[i]);
    }
    return 0;
}