#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILENAME "students.txt"

typedef struct {
    int rollNumber;
    char name[50];
    float grade;
    int attendance;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void loadStudents();
void saveStudents();
void addStudent();
void viewStudents();
void updateStudent();
void deleteStudent();
void displayMenu();

int main() {
    loadStudents(); // Load students from file at the start

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    saveStudents(); // Save students to file before exiting
    return 0;
}

// Load students from file
void loadStudents() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return; // File doesn't exist yet
    }

    while (fscanf(file, "%d %49s %f %d", &students[studentCount].rollNumber, students[studentCount].name, &students[studentCount].grade, &students[studentCount].attendance) != EOF) {
        studentCount++;
    }

    fclose(file);
}

// Save students to file
void saveStudents() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error saving file!\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d %s %.2f %d\n", students[i].rollNumber, students[i].name, students[i].grade, students[i].attendance);
    }

    fclose(file);
}

// Add a new student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    Student newStudent;
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter name: ");
    scanf("%s", newStudent.name);
    printf("Enter grade: ");
    scanf("%f", &newStudent.grade);
    printf("Enter attendance: ");
    scanf("%d", &newStudent.attendance);

    students[studentCount] = newStudent;
    studentCount++;
    printf("Student added successfully.\n");
}

// View all students
void viewStudents() {
    if (studentCount == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\nStudent Details:\n");
    printf("Roll Number | Name          | Grade | Attendance\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-11d | %-12s | %-5.2f | %-10d\n", students[i].rollNumber, students[i].name, students[i].grade, students[i].attendance);
    }
}

// Update a student's details
void updateStudent() {
    int rollNumber;
    printf("Enter roll number of the student to update: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new grade: ");
            scanf("%f", &students[i].grade);
            printf("Enter new attendance: ");
            scanf("%d", &students[i].attendance);
            printf("Student details updated successfully.\n");
            return;
        }
    }

    printf("Student with roll number %d not found.\n", rollNumber);
}

// Delete a student
void deleteStudent() {
    int rollNumber;
    printf("Enter roll number of the student to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Shift all students after the deleted student one position left
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully.\n");
            return;
        }
    }

    printf("Student with roll number %d not found.\n", rollNumber);
}

// Display the menu
void displayMenu() {
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Update Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
}