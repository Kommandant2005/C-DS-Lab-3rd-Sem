#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollno;
    char grade;
};

void readStudents(struct Student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Roll No: ");
        scanf("%d", &students[i].rollno);

        printf("Grade: ");
        scanf(" %c", &students[i].grade);
    }
}


void displayStudents(struct Student students[], int size) {
    printf("Student Information:\n");

    for (int i = 0; i < size; i++) {
        printf("%s\n%d\n%c\n\n", students[i].name, students[i].rollno, students[i].grade);
    }
}

void sortStudents(struct Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].rollno > students[j + 1].rollno) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student students[size];

    readStudents(students, size);
    displayStudents(students, size);

    sortStudents(students, size);

    printf("\nStudent Information after sorting by Roll No:\n");
    displayStudents(students, size);

    return 0;
}

