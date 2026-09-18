#include<stdio.h>
#include<math.h>
int main(void) {
    setbuf(stdout, 0);
    // printf("%lf\n",floor(1.6));
    // printf("%lf\n",ceil(1.6));
    // printf("%lf\n",sin(0));
    // printf("%lf\n",cos(0));
    // printf("%lf\n",sin(90));
    // printf("%lf\n",pow(2,8));
    // printf("%lf\n",sqrt(2));


    printf("%0.25lf\n",0.1);
    printf("%0.25lf\n",0.2);
    printf("%0.25lf\n",0.3);
    printf("%0.25lf\n",0.1+0.2);

    if((0.1+0.2)==0.3) {
        printf("true");
    }
    double i= 0.1;
    for ( ; i <= 100000000 ; i+=0.1);
    printf("%0.25lf\n",i);


    return 0;
}