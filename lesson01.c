#include <stdio.h>

int countLetters(char message[]) {
    int count = 0;
    while (message[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    int length = countLetters("Hello");
    printf("Length: %d\n", length);
    return 0;
}
