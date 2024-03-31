#ifndef STUDENT_H
#define STUDENT_H

void inputStudentData(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents);
void generateGradeCard(char names[][50], int rollNumbers[], int marks[][5], int numStudents, char *examName);
void generateFinalGradeCard(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents);
void addStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int *numStudents);
void updateStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents);
void deleteStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int *numStudents);
void viewFinalGradeCardOfStudent(char names[][50], int rollNumbers[], int isa1[][5], int isa2[][5], int ESA[][5], int numStudents);

#endif
