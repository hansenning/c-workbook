#include <stdio.h>

void addOne(int *p) {
    *p = *p + 1;
}

int main() {
    int a = 5;
    addOne(&a);
    printf("%d\n", a);
    return 0;
}
