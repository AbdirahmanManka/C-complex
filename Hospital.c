#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

// Define structures for Patients and Appointments
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char disease[100];
} Patient;

typedef struct {
    int patientID;
    char doctorName[MAX_NAME_LEN];
    char date[15];
} Appointment;

// Function to add a patient
void addPatient() {
    FILE *file = fopen("patients.dat", "ab");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Patient p;
    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);
    getchar(); // Clear buffer
    printf("Enter Patient Name: ");
    fgets(p.name, MAX_NAME_LEN, stdin);
    strtok(p.name, "\n"); // Remove newline character
    printf("Enter Age: ");
    scanf("%d", &p.age);
    getchar();
    printf("Enter Disease: ");
    fgets(p.disease, sizeof(p.disease), stdin);
    strtok(p.disease, "\n");

    fwrite(&p, sizeof(Patient), 1, file);
    fclose(file);

    printf("Patient added successfully!\n");
}

// Function to view all patients
void viewPatients() {
    FILE *file = fopen("patients.dat", "rb");
    if (!file) {
        printf("No patient records found!\n");
        return;
    }

    Patient p;
    printf("\n=== Patient List ===\n");
    while (fread(&p, sizeof(Patient), 1, file)) {
        printf("ID: %d | Name: %s | Age: %d | Disease: %s\n", p.id, p.name, p.age, p.disease);
    }
    fclose(file);
}

// Function to book an appointment
void bookAppointment() {
    FILE *file = fopen("appointments.dat", "ab");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Appointment a;
    printf("\nEnter Patient ID: ");
    scanf("%d", &a.patientID);
    getchar();
    printf("Enter Doctor's Name: ");
    fgets(a.doctorName, MAX_NAME_LEN, stdin);
    strtok(a.doctorName, "\n");
    printf("Enter Appointment Date (DD/MM/YYYY): ");
    fgets(a.date, sizeof(a.date), stdin);
    strtok(a.date, "\n");

    fwrite(&a, sizeof(Appointment), 1, file);
    fclose(file);

    printf("Appointment booked successfully!\n");
}

// Function to generate a bill
void generateBill() {
    FILE *file = fopen("bills.txt", "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    int patientID;
    float amount;
    printf("\nEnter Patient ID: ");
    scanf("%d", &patientID);
    printf("Enter Bill Amount: $");
    scanf("%f", &amount);

    fprintf(file, "Patient ID: %d | Bill Amount: $%.2f\n", patientID, amount);
    fclose(file);

    printf("Bill generated successfully!\n");
}

// Main menu
void menu() {
    int choice;
    do {
        printf("\n=== Hospital Management System ===\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Book Appointment\n");
        printf("4. Generate Bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear buffer

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: bookAppointment(); break;
            case 4: generateBill(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
}

// Main function
int main() {
    menu();
    return 0;
}
