#include <stdio.h>

struct Student {
    char name[50];
    int age;
    int grade;
};

int main() {
    struct Student class[3];

    class[0].age = 20;
    class[0].grade = 85;

    class[1].age = 21;
    class[1].grade = 90;

    class[2].age = 19;
    class[2].grade = 78;

    for (int i = 0; i < 3; i++) {
        printf("Student %d: age %d, grade %d\n", i, class[i].age, class[i].grade);
    }
    return 0;
}
