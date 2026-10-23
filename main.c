#include <stdio.h>
#include <string.h>
int __cdecl mystrcmp(const char *_Str1, const char *_Str2) {
    // Loop until we reach the end of one string or a mismatch occurs
    while (*_Str1 && (*_Str1 == *_Str2)) {
        _Str1++;
        _Str2++;
    }

    // Return the difference between the mismatched characters
    return *(const unsigned char *)_Str1 - *(const unsigned char *)_Str2;
}
int  mystrlen(const char *_Str) {
    const char *s = _Str;
    while (*s) {
        s++;
    }
    return (size_t)(s - _Str);
}
char * __cdecl mystrcpy(char * __restrict__ _Dest, const char * __restrict__ _Source) {
    char *save = _Dest;
    while ((*_Dest++ = *_Source++) != '\0');
    return save;
}

int main() {
    setbuf(stdout,0);
    char *name = "arushi";
    printf("%d\n",mystrlen(name));
    printf("%s\n",name);
    puts(name);
    printf("%p\n",name);
    printf("%c\n",name[2]);
   // name[2] = 'U';//read only string
    // char *anothername = NULL;
    // strcpy(anothername,"praneetha");//cant be applied to pointer string
    // anothername = strcpy(anothername,"praneetha");
    printf("%s\n",name);
    // printf("%s\n",anothername);
    char staticname[50];
    strcpy(staticname,"praneetha");
    printf("%s\n",staticname);
    printf("%d\n",strlen("praneetha\0"));
    char *anothername = "praneetha";
    //strcpy(anothername,"praneetha");//cant be applied to pointer string
    // anothername = mystrcpy(anothername,"praneetha\0");
    // printf("%s\n",anothername);
    printf("%d\n",strcmp(name,anothername));
    printf("%d\n",strcmp("praneetha","praneetha"));
    printf("%d\n",mystrcmp("ruchi","raneetha"));
    printf("%s\n",strrev(staticname));
    printf("%s\n",strchr(name,'h'));
    printf("%s\n",staticname);
    strcat(staticname,"hig");
    printf("%s\n",staticname);
    printf("%s\n",strstr(staticname,"hi"));
    return 0;
}
