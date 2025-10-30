#include <stdio.h>

int main() {
    int x=10;
    int *ptr=&x;

    (*ptr)++;
    printf("Value of x: %d\n", x);

    return 0;
}
