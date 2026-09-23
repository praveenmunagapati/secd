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
    /*
    *   The 5 Steps of Bubble Sort
        Start: Begin at the very first element (index 0) of the list.
        Compare: Look at two neighboring elements side by side.
        Swap: If the first element is bigger than the second element, switch their places so the larger value moves to the right.
        Repeat for the pass: Move to the next pair of neighbors and repeat the comparison and swapping until you reach the end of the unsorted part of the list.
        Continue sorting: Go back to the start of the list for a new pass, ignoring the elements that are already sorted at the end, and stop when a full pass happens with zero swaps.
     */
    printf("before sorting\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d\t",array[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (array[i]<array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("after sorting\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d\t",array[i]);
    }

    return 0;
}