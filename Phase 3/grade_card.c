#include <stdio.h>
#include <string.h>
#include "grade_card.h"

#define NUM_STUDENTS 10
#define NUM_SUBJECTS 5
#define NUM_EXAMS 3

struct Student {
    int id;
    char name[50];
    float marks_data[NUM_EXAMS][NUM_SUBJECTS];
};

struct Student students[NUM_STUDENTS];
int student_count = 0;

char calculate_grade(float marks) {
    if (marks >= 90)
        return 'A';
    else if (marks >= 80)
        return 'B';
    else if (marks >= 70)
        return 'C';
    else if (marks >= 60)
        return 'D';
    else
        return 'F';
}

void initialize_students() {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        students[i].id = 0;
        students[i].name[0] = '\0';
    }
}

void add_student() {
    if (student_count < NUM_STUDENTS) {
        printf("Enter student ID: ");
        scanf("%d", &students[student_count].id);
        printf("Enter student name: ");
        scanf("%s", students[student_count].name);

        // Input marks for each subject for each exam
        for (int exam = 0; exam < NUM_EXAMS; exam++) {
            printf("Enter marks for Exam %d:\n", exam + 1);
            for (int subject = 0; subject < NUM_SUBJECTS; subject++) {
                printf("Enter marks for Subject %d: ", subject + 1);
                scanf("%f", &students[student_count].marks_data[exam][subject]);
            }
        }

        student_count++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum student limit reached.\n");
    }
    save_to_csv("student.csv");
}

void update_student() {
    int id, index = -1;
    printf("Enter student ID to update: ");
    scanf("%d", &id);

    // Search for the student
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Enter new name for student: ");
        scanf("%s", students[index].name);

        // Input marks for each subject for each exam
        for (int exam = 0; exam < NUM_EXAMS; exam++) {
            printf("Enter marks for Exam %d:\n", exam + 1);
            for (int subject = 0; subject < NUM_SUBJECTS; subject++) {
                printf("Enter marks for Subject %d: ", subject + 1);
                scanf("%f", &students[index].marks_data[exam][subject]);
            }
        }
        printf("Student information updated successfully.\n");
    } else {
        printf("Student not found.\n");
    }
    save_to_csv("student.csv");
}

void delete_student() {
    int id, index = -1;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < student_count - 1; i++) {
            students[i] = students[i + 1];
        }
        student_count--;
        printf("Student deleted successfully.\n");
    } else {
        printf("Student not found.\n");
    }
    save_to_csv("student.csv");
}

void display_single_student_grade() {
    int id, index = -1;
    printf("Enter student ID to display grade: ");
    scanf("%d", &id);
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        float total_marks = 0;
        for (int exam = 0; exam < NUM_EXAMS; exam++) {
            for (int subject = 0; subject < NUM_SUBJECTS; subject++) {
                total_marks += students[index].marks_data[exam][subject];
            }
        }
        float average_marks = total_marks / (NUM_EXAMS * NUM_SUBJECTS);
        char grade = calculate_grade(average_marks);
        printf("\nStudent ID: %d\n", students[index].id);
        printf("Student Name: %s\n", students[index].name);
        printf("Average Marks: %.2f\n", average_marks);
        printf("Grade: %c\n", grade);
    } else {
        printf("Student not found.\n");
    }
    save_to_csv("student.csv");
}

void save_to_csv(const char *filename) {
    FILE *file = fopen("student.csv", "w");
    if (!file) {
        printf("Unable to open file for writing.\n");
        return;
    }

    // Write the header
    fprintf(file, "ID,Name");
    for (int exam = 0; exam < NUM_EXAMS; exam++) {
        for (int subject = 0; subject < NUM_SUBJECTS; subject++) {
            fprintf(file, ",Exam%d_Subject%d", exam + 1, subject + 1);
        }
    }
    fprintf(file, "\n");

    // Write the student data
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%d,%s", students[i].id, students[i].name);
        for (int exam = 0; exam < NUM_EXAMS; exam++) {
            for (int subject = 0; subject < NUM_SUBJECTS; subject++) {
                fprintf(file, ",%.2f", students[i].marks_data[exam][subject]);
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Data saved to %s successfully.\n", "student.csv");
}