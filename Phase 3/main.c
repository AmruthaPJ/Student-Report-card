#include <stdio.h>
#include "grade_card.h"

int main() {
    int choice;
    initialize_students();
    
    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Display Single Student Grade\n");
        printf("5. Save to CSV\n");
        printf("6. Exit\n");
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
                save_to_csv("student.csv");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
