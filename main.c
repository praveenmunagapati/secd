#include<stdio.h>

int main(void) {
    start:
    setbuf(stdout, 0);
    //looooops
    // while do for
    //break continue goto
    //print 1 to 10
    printf("1\n");
    printf("2\n");
    printf("3\n");
    printf("4\n");
    printf("5\n");
    printf("6\n");
    printf("7\n");
    printf("8\n");
    printf("9\n");
    printf("10\n");
    //scalars
    printf("%d\n", 1);
    printf("%d\n", 2);
    printf("%d\n", 3);
    printf("%d\n", 4);
    printf("%d\n", 5);
    printf("%d\n", 6);
    printf("%d\n", 7);
    printf("%d\n", 8);
    printf("%d\n", 9);
    printf("%d\n", 10);
    int var = 1;
    printf("%d\n", var);
    var = var + 1;
    printf("%d\n", var);
    var = var + 1;
    printf("%d\n", var);
    var = var + 1;
    printf("%d\n", var);
    var = var + 1;
    printf("%d\n", var);
    var = var + 1;
    printf("%d\n", var);
    var = var + 1;
    printf("%d\n", var);
    var = var + 1;
    printf("%d\n", var);
    var = var + 1;
    printf("%d\n", var);
    var = var + 1;
    printf("%d\n", var);

    var = 1;
    printf("%d\n", var++);
    printf("%d\n", var++);
    printf("%d\n", var++);
    printf("%d\n", var++);
    printf("%d\n", var++);
    printf("%d\n", var++);
    printf("%d\n", var++);
    printf("%d\n", var++);
    printf("%d\n", var++);
    printf("%d\n", var++);
    var = 1;
    //while
    while (var <= 10) {
        printf("%d\n", var++);
    }
    var = 1;

    while (0) {
        printf("hi");
    }
    while (1) {
        printf("praneetha");
        break;
    }
    while (0) {
        printf("hi");
    }
    do {
        printf("x");
    } while (0);

    //for
    /*
     *
     */
    var = 1;
    //while
    while (var <= 10) {
        printf("%d\n", var++);
    }
    for (int var = 1;var <= 10;var++) {
        printf("%d\n", var);
    }
    for (;1;) {
        printf("praneetha\n");
        break;
    }

    //continue
    var = 1;
    while (var <= 10) {
        if (var == 5) {
            var++;
            continue;
        }
        printf("%d\n", var++);
    }
    var = 1;
    while (var <= 10) {
        if (var % 2 == 1) {
            var++;
            continue;
        }
        printf("%d\n", var++);
    }
    var = 1;
    while (var <= 10) {
        if (var % 2 == 0) {
            var++;
            continue;
        }
        printf("%d\n", var++);
    }
    //goto

    greetings:
        printf("anitha\n");
        goto exit;
    goto greetings;
    exit:
        printf("never goto \n");

    goto start;
    return 0;
}
