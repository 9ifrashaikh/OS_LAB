// zombie and orphan process 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to demonstrate a Zombie Process
void zombie_process() {
    pid_t pid = fork();
    if (pid > 0) {
        printf("Parent process sleeping...\n");
        sleep(10);  // Parent process sleeps for 10 seconds
        printf("Parent process finished sleeping.\n");
    } else if (pid == 0) {
        printf("Child process (Zombie) exiting...\n");
        exit(0); // Child exits, becomes a zombie until parent collects it
    } else {
        perror("Fork failed");
    }
}

// Function to demonstrate an Orphan Process
void orphan_process() {
    pid_t pid = fork();
    if (pid > 0) {
        printf("Parent process exiting...\n");
        exit(0);  // Parent process exits
    } else if (pid == 0) {
        sleep(5); // Child process sleeps to become an orphan
        printf("Child process (Orphan) running, adopted by init.\n");
    } else {
        perror("Fork failed");
    }
}

// Function to calculate the sum of even numbers in the parent process
// and odd numbers in the child process
void sum_even_odd(int arr[], int size) {
    pid_t pid = fork();
    int sum = 0;

    if (pid > 0) { // Parent process: calculate sum of even numbers
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0) sum += arr[i];
        }
        wait(NULL); // Wait for the child to finish
        printf("Parent Process: Sum of even numbers = %d\n", sum);
    } else if (pid == 0) { // Child process: calculate sum of odd numbers
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 != 0) sum += arr[i];
        }
        printf("Child Process: Sum of odd numbers = %d\n", sum);
        exit(0);
    } else {
        perror("Fork failed");
    }
}

// Main Menu-Driven Program
int main() {
    int choice;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example array

    do {
        printf("\nMenu:\n");
        printf("1. Zombie Process\n");
        printf("2. Orphan Process\n");
        printf("3. Sum of Even and Odd Numbers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                zombie_process();
                break;
            case 2:
                orphan_process();
                break;
            case 3:
                sum_even_odd(arr, 10);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
