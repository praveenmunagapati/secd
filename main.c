#include <stdio.h>
#include <string.h>


int main() {
    setbuf(stdout,0);
    char anames[3][20] = {{"praneetha"},{"hanish"},{"ram"}};
    printf("%d\n",sizeof(anames));
    strcpy(anames[0],"hanish");
    strcpy(anames[2],"praneetha");
    strcpy(anames[1],"ram");
    for (int i = 0; i < 3; ++i) {
        printf("name %s\n",anames[i]);
    }
    char *names[3];
    names[0]="praneetha";
    names[1]="hanish";
    names[2]="ram";
    puts(names[0]);
    puts(names[1]);
    puts(names[2]);
    return 0;
}
