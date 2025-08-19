#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

void readStudents(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Roll Number: ");
        scanf("%d", &s[i].roll_no);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void displayStudents(struct Student *s, int n) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Roll No: %d\n", s[i].roll_no);
        printf("Marks: %.2f\n", s[i].marks);
        printf("--------------------\n");
    }
}

void displayTopper(struct Student *s, int n) {
    struct Student *topper = s;

    for (int i = 1; i < n; i++) {
        if ((s + i)->marks > topper->marks) {
            topper = s + i;
        }
    }

    printf("\nTopper Details:\n");
    printf("Name: %s\n", topper->name);
    printf("Roll No: %d\n", topper->roll_no);
    printf("Marks: %.2f\n", topper->marks);
}

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    readStudents(students, n);
    displayStudents(students, n);
    displayTopper(students, n);

    return 0;
}
