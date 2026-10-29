#include <stdio.h>
#include<string.h>
struct student {
    char *names;
    int ppsmarks;
};
void callbyreference(int *p) {
    *p = 156;
}
void callbyreferencearray(int *pa) {

    for (int i = 0; i < 5; ++i) {
        printf("%d\t",pa[i]);
    }
}
int main() {
    setbuf(stdout,0);
    char *names[3];
    int ppsmarks[3];
    names[0]="praneetha";
    names[1]="hanish";
    names[2]="ram";
    puts(names[0]);
    puts(names[1]);
    puts(names[2]);

    char anames[3][20] = {{"praneetha"},{"hanish"},{"ram"}};
    printf("%d\n",sizeof(anames));
    strcpy(anames[0],"hanish");
    strcpy(anames[0],"praneetha");
    strcpy(anames[0],"ram");
    ppsmarks[0] = 80;
    ppsmarks[1] = 90;
    ppsmarks[2] = 78;
    for (int i = 0; i < 3; ++i) {
        printf("name %s marks %d\n",anames[i],ppsmarks[i]);
    }
    // struct student[3];

    int x = 10;
    printf("%d\n",x);
    printf("%p\n",&x);
    printf("%d\n",*(&x));
    int *p = &x;
    *p = 15;
    printf("%d\n",*p);
    printf("%d\n",*p+5);
    printf("%d\n",*(p+5));
    printf("%p\n",(p+5));
    int array[5] = {8,9,5,4,6};
    for (int i = 0; i < 5; ++i) {
        printf("%d\t",array[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d\t",i[array]);
    }
    printf("\n");

    for (int i = 0; i < 5; ++i) {
        printf("%p\t",(array +  i));
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\t",*(array +  i));
    }
    callbyreference(&x);
    printf("%d\n",x);
    printf("\n");

    printf("%p\n",&array);
    printf("%p\n",&array[0]);
    printf("\n");

    int *pa;
    pa = array;
    for (int i = 0; i < 5; ++i) {
        printf("%p\t",&array[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%p\t",&pa[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\t",pa[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\t",*(pa + i));
    }
    callbyreferencearray(array);
    for (int i = 0; i < 5; ++i) {
        printf("%d\t",*pa++);
    }
    printf("\n");

    char mynamea[5] = {'y','u','v','a','\0'};
    puts(mynamea);
    for (int i = 0; i < 5; ++i) {
        printf("%p\t",&mynamea[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%c\t",mynamea[i]);
    }
    printf("\n");

    char *myname = "yuva";
    for (int i = 0; i < 5; ++i) {
        printf("%p\t",&myname[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%c\t",myname[i]);
    }
    printf("\n");

    // for (int i = 0; i < 5; ++i) {
    //     printf("%c\t",*myname++);
    // }
    while (*myname) {
        printf("%c\t",*myname);
        *myname++;
    }
    printf("\n");

    printf("%c\t",*myname);
    *myname--;
    printf("%c\t",*myname);
    *myname--;
    printf("%c\t",*myname);
    *myname--;
    printf("%c\t",*myname);
    *myname--;
    printf("%c\t",*myname);
    *myname--;



    return 0;
}
