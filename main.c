#include<stdio.h>
#include<string.h>
int main(void) {
    setbuf(stdout, 0);
    //parallel arrays
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
    int id = 1;
    for (int i = 0; i < 3; ++i) {
        if (id==i) {
            printf("name %s marks %d\n",anames[i],ppsmarks[i]);
        }
    }
    return 0;
}