#include<stdio.h>
int main(void) {
    setbuf(stdout,0);
    //bitwise operators
    //& | ^ ~ << >>
    //bitwise and &
 /*   a b  &
    0 0  0
    0 1  0
    1 0  0
    1 1  1
    */
    printf("%d\n",17&5);
    // 7 -> 111
    //5  -> 101
    //&  ->  101
    //17 ->  10001
    //5  ->  00101
    //&  ->   00001
    printf("%d\n",17^5);
    /*   a b |
       0 0  0
       0 1  1
       1 0  1
       1 1  1
       */
    //17 ->  10001
    //5  ->  00101
    //|  ->   10101
    /*   a b ^
   0 0  0
   0 1  1
   1 0  1
   1 1  0
   */
    //17 ->  10001
    //5  ->  00101
    //^  ->   10100

    //bitwise complement ~


return 0;
}