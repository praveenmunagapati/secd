#include <stdio.h>
#include <string.h>
int  mystrlen(const char *_Str) {
    const char *s = _Str;
    while (*s) {
        s++;
    }
    return (size_t)(s - _Str);
}
int  mystrlenr(const char *_Str) {
    const char *s = _Str;
    if (*s=='\000') {
        return 0;
    }
    return 1 + mystrlenr(s + 1);
}
int main() {
    setbuf(stdout,0);
    char *name = "bharathi";
    printf("%s\n",name);
    printf("%d\n",strlen(name));
    printf("%d\n",mystrlen(name));
    //printf("%d\n",mystrlenr(name));

    while (*name) {
        printf("%c\n",*name);
        name++;
    }
    name = "bharathi";
    printf("%d\n",mystrlenr(name));
    return 0;
}
