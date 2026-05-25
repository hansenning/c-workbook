#include <stdio.h>

int main() {
    int a = 7;
    int *p = &a;
    *p = 99;
    printf("%d\n", a);
    return 0;
}


