#include<stdio.h>
#include<string.h>
enum WEEK {
    MONDAY=-5,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
enum MACHINE {
    TEA=1,
    COFFEE,
    BOOST,

};
int main(void) {
    setbuf(stdout, 0);
    printf("%d\n",sizeof(enum WEEK));
    printf("%d\n",MONDAY);
    printf("%d\n",TUESDAY);
    printf("%d\n",WEDNESDAY);
    printf("%d\n",THURSDAY);
    printf("%d\n",FRIDAY);
    printf("%d\n",SATURDAY);
    printf("%d\n",SUNDAY);
   //MONDAY = 1;//error

    int choice = 4;
    switch (choice) {
        case 1 : printf("you get tea \n");break;
        case 2 : printf("you get coffee \n");break;
        case 3 : printf("you get boost \n");break;
            default:printf("wrong choice\n");break;
    }
    choice =COFFEE;
    switch (choice) {
        case TEA : printf("you get tea \n");break;
        case COFFEE : printf("you get coffee \n");break;
        case BOOST : printf("you get boost \n");break;
        default:printf("wrong choice\n");break;
    }
    return 0;
}