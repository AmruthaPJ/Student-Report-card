#include <stdio.h>
#include "student.h"
int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    char names[numStudents][50];
    int rollNumbers[numStudents];
    int isa1[numStudents][5], isa2[numStudents][5], ESA[numStudents][5];
    inputStudentData(names, rollNumbers, isa1, isa2, ESA, numStudents);
    int choice;
    do {
        printf("\nOptions:\n");
        printf("1. Generate Grade Card for ISA 1\n");
        printf("2. Generate Grade Card for ISA 2\n");
        printf("3. Generate Grade Card for ESA\n");
        printf("4. Generate Final Grade Card\n");
        printf("5. Add Student\n");
        printf("6. Update Student\n");
        printf("7. Delete Student\n");
        printf("8. View Final Grade Card of a Student\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                generateGradeCard(names, rollNumbers, isa1, numStudents, "ISA 1");
                break;
            case 2:
                generateGradeCard(names, rollNumbers, isa2, numStudents, "ISA 2");
                break;
            case 3:
                generateGradeCard(names, rollNumbers, ESA, numStudents, "ESA");
                break;
            case 4:
                generateFinalGradeCard(names, rollNumbers, isa1, isa2, ESA, numStudents);
                break;
            case 5:
                addStudent(names, rollNumbers, isa1, isa2, ESA, &numStudents);
                break;
            case 6:
                updateStudent(names, rollNumbers, isa1, isa2, ESA, numStudents);
                break;
            case 7:
                deleteStudent(names, rollNumbers, isa1, isa2, ESA, &numStudents);
                break;
            case 8:
                viewFinalGradeCardOfStudent(names, rollNumbers, isa1, isa2, ESA, numStudents);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 0);
    return 0;
}