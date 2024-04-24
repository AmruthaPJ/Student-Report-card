#include <stdio.h>
#include "grade_card.h"
int main() {
    int choice;
    initialize_students();
    do {
        printf("\n1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Display Grade of a Single Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                update_student();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                display_single_student_grade();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;}