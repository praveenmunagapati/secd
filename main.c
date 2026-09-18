#include<stdio.h>
#include<math.h>
int main(void) {
    setbuf(stdout, 0);
    int x = 10;
    printf("%d\n",x);
    printf("%p\n",&x);
    printf("%d\n",*(&x));
    //pointer
    //rule 1 pointer never hold any value
    //it only holds address
    int *px;
    px = &x;
    printf("%p\n",&px);
    printf("%p\n",px);
    printf("%d\n",*px);
    printf("%d\n",sizeof(px));
    *px = 15;
    printf("%d\n",x);
    *px += 15;
    printf("%d\n",x);
    int k = 89;
    px = &k;
    printf("%p\n",&px);
    printf("%p\n",&k);
    printf("%p\n",px);
    printf("%d\n",*px);

   float f = 1.5;
    //px = &f; //not gonna work only int tyle
   // printf("%f\n",*px);
    short s = 10;
    // px = &s; //only int types
    // printf("%d\n",*px);
    int l = 5;
    // px = &l; //only int type
    // printf("%d\n",*px);
    //generic pointer
    void *gp = &l;
    printf("%i\n",*(int *)gp);
    gp = &f;
    printf("%f\n",*(float *)gp);
    gp = &s;
    printf("%i\n",*(short *)gp);
    return 0;
}