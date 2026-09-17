#include<stdio.h>
void tableprint(int table,int row);//function signature
int main(void) {
    setbuf(stdout, 0);
//c) Write a program that prints a multiplication table
//for a given number and the number of rows in
// the table. For example, for a number 5 and rows = 3,
// the output should be:
// 5 x 1 = 5
// 5 x 2 = 10
// 5 x 3 = 15

    int table = 19;
    int row = 10;
    for (int i = 1; i<=row;i++) {
        printf("%d x %d = %d\n",table,i,table * i);
    }
    tableprint(15,10);
    tableprint(19,10);
    tableprint(89,10);
    tableprint(157,10);
    tableprint(689,10);
    tableprint(265,10);
    tableprint(10,10);



    return 0;
}
void tableprint(int table,int row) {
    for (int i = 1; i<=row;i++) {
        printf("%d x %d = %d\n",table,i,table * i);
    }
    return;
}