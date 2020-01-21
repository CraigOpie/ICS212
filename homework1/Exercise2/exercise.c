#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int num1, num2 = 5;
    char c = 'A';
    float score1 = 25.5;
    char ca[3] = "Hi";

    dummy(num2, c, ca, score1);

    /* pause here */

    return 0;
}

void dummy(int x, char y, char * z, float w)
{
    x++;
    y++;
    w = w + 5.1;
}
