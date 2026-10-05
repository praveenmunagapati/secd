#include<stdio.h>
int main(void) {
    setbuf(stdout, 0);
    //storage classes
    //auto      → "Create me when block starts; destroy me when block ends."
    //register  → "I may be kept in a CPU register; don't assume I have an address."

    //static    → "Create me once; keep me alive."

    //extern    → "I am defined somewhere else."

    //auto
    //int i = 10;
    auto signed int i = 10;
    printf("%d\n",i);
    {
       auto int j = 5;
        printf("%d\n",i);
    }
    //register
    register  int fastvariable = 15;
    printf("%d\n",sizeof fastvariable);
    //printf("%d\n",&fastvariable);//cant access address of register
    // printf("%d\n",j);
    auto int k;
    printf("%d\n",k);
    register int r;
    printf("%d\n",r);

    return 0;
}