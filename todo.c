#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100  // Maximum number of tasks
#define MAX_LENGTH 100 // Maximum length of a task

char tasks[MAX_TASKS][MAX_LENGTH]; // Array to store tasks
int taskCount = 0; // Number of tasks

// Function to add a task
void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter task: ");
        getchar(); // Clear newline from previous input
        fgets(tasks[taskCount], MAX_LENGTH, stdin);
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0; // Remove newline
        taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
    }
}

// Function to remove a task
void removeTask() {
    if (taskCount == 0) {
        printf("No tasks to remove!\n");
        return;
    }
    
    int index;
    printf("Enter task number to remove (1 to %d): ", taskCount);
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("Invalid task number!\n");
    } else {
        // Shift tasks to the left to remove the selected task
        for (int i = index - 1; i < taskCount - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }
        taskCount--;
        printf("Task removed successfully!\n");
    }
}

// Function to display tasks
void displayTasks() {
    if (taskCount == 0) {
        printf("No tasks available!\n");
        return;
    }

    printf("\nTo-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

// Main function with menu
int main() {
    int choice;
    
    do {
        printf("\n===== TO-DO LIST MENU =====\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: removeTask(); break;
            case 3: displayTasks(); break;
            case 4: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
