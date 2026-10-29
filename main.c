#include <stdio.h>
#include<string.h>
struct student {
    char *names;
    int ppsmarks;
};
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
    struct student s1;
    printf("%d\n",sizeof(s1));
    printf("%d\n",sizeof(s1.names));
    printf("%d\n",sizeof(s1.ppsmarks));
    printf("%p\n",&s1);
    printf("%p\n",&s1.names);
    printf("%p\n",&s1.ppsmarks);
    s1.names = "jio";
    s1.ppsmarks = 25;
    printf("%d\n",s1.names);
    printf("%d\n",s1.ppsmarks);

    struct student csmd[3];
    printf("%d\n",sizeof(struct student));
    printf("%d\n",sizeof(csmd[0].names));
    printf("%d\n",sizeof(csmd[0].ppsmarks));
    csmd[0].names = "rahul";
    csmd[0].ppsmarks = 25;
    csmd[1].names = "radha";
    csmd[1].ppsmarks = 24;
    csmd[2].names = "krishna";
    csmd[2].ppsmarks = 20;
    printf("%s\n",csmd[0].names);
    printf("%d\n",csmd[0].ppsmarks);
    printf("%s\n",csmd[1].names);
    printf("%d\n",csmd[1].ppsmarks);
    printf("%s\n",csmd[2].names);
    printf("%d\n",csmd[2].ppsmarks);


    return 0;
}
