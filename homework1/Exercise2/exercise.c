#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    printf("argc = %d\n", argc);
    printf("%x argc = %p\n", &argc, &argc);
    printf("%x argv = %p\n", &argv[0], &argv[0]);
    printf("%x argv w/p = %p\n", argv[0], argv[0]);
    int num1, num2 = 5;
    printf("%x num1 = %p\n", &num1, &num1);
    printf("%x num2 = %p\n", &num2, &num2);
    char c = 'A';
    printf("%x c = %p\n", &c, &c);
    float score1 = 25.5;
    printf("%x score1 = %p\n", &score1, &score1);
    char ca[3] = "Hi";
    printf("%x ca[0] = %c\n", &ca[0], ca[0]);
    printf("%x ca[1] = %c\n", &ca[1], ca[1]);
    printf("%x ca[2] = %c\n", &ca[2], ca[2]);

    dummy(num2, c, ca, score1);

    /* pause here */

    return 0;
}

void dummy(int x, char y, char * z, float w)
{
    printf("%x x = %p\n", &x, &x);
    printf("%x y = %p\n", &y, &y);
    printf("%x *z = %p\n", &z, &z);
    printf("%x *z w/p = %p\n", z, z);
    printf("%x w = %p\n", &w, &w);
    x++;
    printf("%x x = %p\n", &x, &x);
    y++;
    printf("%x y = %c\n", &y, y);
    w = w + 5.1;
    printf("%x w = %.2f\n", &w, w);
}
