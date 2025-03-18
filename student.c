#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

typedef struct {
    int id;
    char name[50];
    int age;
    float grade;
    int attendance;
} Student;

// Function prototypes
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;
    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear buffer

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to add a student
void addStudent() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    getchar();
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove newline
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Grade: ");
    scanf("%f", &s.grade);
    printf("Enter Attendance Percentage: ");
    scanf("%d", &s.attendance);

    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No records found!\n");
        return;
    }

    Student s;
    printf("\n=== Student Records ===\n");
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("ID: %d | Name: %s | Age: %d | Grade: %.2f | Attendance: %d%%\n",
               s.id, s.name, s.age, s.grade, s.attendance);
    }
    fclose(file);
}

// Function to search for a student by ID
void searchStudent() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No records found!\n");
        return;
    }

    int searchID;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchID);

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.id == searchID) {
            printf("ID: %d | Name: %s | Age: %d | Grade: %.2f | Attendance: %d%%\n",
                   s.id, s.name, s.age, s.grade, s.attendance);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Student with ID %d not found!\n", searchID);
    }
}

// Function to update a student's details
void updateStudent() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        printf("No records found!\n");
        return;
    }

    int searchID;
    printf("Enter Student ID to update: ");
    scanf("%d", &searchID);

    Student s;
    int found = 0;
    long pos;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.id == searchID) {
            found = 1;
            pos = ftell(file) - sizeof(Student);

            printf("Enter New Name: ");
            getchar();
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0;
            printf("Enter New Age: ");
            scanf("%d", &s.age);
            printf("Enter New Grade: ");
            scanf("%f", &s.grade);
            printf("Enter New Attendance Percentage: ");
            scanf("%d", &s.attendance);

            fseek(file, pos, SEEK_SET);
            fwrite(&s, sizeof(Student), 1, file);
            printf("Student record updated successfully!\n");
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Student with ID %d not found!\n", searchID);
    }
}

// Function to delete a student record
void deleteStudent() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No records found!\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temp file!\n");
        fclose(file);
        return;
    }

    int searchID;
    printf("Enter Student ID to delete: ");
    scanf("%d", &searchID);

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.id == searchID) {
            found = 1;
            printf("Student record deleted successfully!\n");
        } else {
            fwrite(&s, sizeof(Student), 1, temp);
        }
    }
    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (!found) {
        printf("Student with ID %d not found!\n", searchID);
    }
}
