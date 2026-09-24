#include<stdio.h>
#include<string.h>
int main(void) {
    setbuf(stdout, 0);
    //parallel arrays
    int array[10] = {15,78,14,59,3,45,72,9,6,7};
    //strings
    char name[10] = {'p','r','a','n','e','e','t','h','a','\0'};//null indecats end of string
    for (int i = 0; i < 10; ++i) {
        printf("%c",name[i]);
    }
    printf("\n%s\n",name);
    puts(name);
    char *me = "muskaan";
    printf("\n%p",me);//address where the string created
    printf("\n%s",me);
    printf("\n%d",strlen(me));
    printf("\n%d",strlen(name));
    strcpy(name,me);
    return 0;
}