#include <stdio.h>

void foo(void) {
    // int array[100000000]= {0};
    printf("foo\n");
    foo();
    return;
}

void foo1(void) {
    // int array[100000000]= {0};
    int i = 1;
    printf("%d\n",i++);
    foo1();
    return;
}

void foo2(int i) {
    // int array[100000000]= {0};
    printf("%d\n",i++);
    foo2(i);
    return;
}

void foo3(int i) {

    if (i == 11) {
        return ;
    }
    printf("%d\n",i++);
    foo3(i);
    return;
}
int main() {
    setbuf(stdout,0);
    // foo();//bad idea
    //foo1();//bad idea 1
    //foo2(1);//no exit condition
    foo3(1);
    return 0;
}
