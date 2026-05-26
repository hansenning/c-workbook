#include <stdio.h>

struct Student {
    char name[50];
    int age;
    int grade;
};

int main() {
	//stuck student is the id card template
	//s1 is the actually card
    struct Student s1;
    s1.age = 20;
    s1.grade = 85;

    printf("Age: %d\n", s1.age);
    printf("Grade: %d\n", s1.grade);
    return 0;
}
