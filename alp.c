// ALP program to main memory 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 100      // Define the size of simulated memory
#define INSTRUCTION_LENGTH 50 // Maximum length of an instruction

// Function to load ALP from input file into main memory
int loadALP(const char *inputFile, char memory[MEMORY_SIZE][INSTRUCTION_LENGTH]) {
    FILE *file = fopen(inputFile, "r");
    if (file == NULL) {
        printf("Error: Unable to open input file.\n");
        return -1;
    }

    int i = 0;
    while (fgets(memory[i], INSTRUCTION_LENGTH, file) != NULL) {
        // Remove trailing newline character if present
        memory[i][strcspn(memory[i], "\n")] = '\0';
        i++;
        if (i >= MEMORY_SIZE) {
            printf("Error: Memory overflow. Too many instructions.\n");
            break;
        }
    }

    fclose(file);
    return i; // Return the number of instructions loaded
}

void displayMemory(char memory[MEMORY_SIZE][INSTRUCTION_LENGTH], int instructionCount) {
    printf("\nLoaded Assembly Program in Memory:\n");
    for (int i = 0; i < instructionCount; i++) {
        printf("Memory[%02d]: %s\n", i, memory[i]);
    }
}

int main() {
    char memory[MEMORY_SIZE][INSTRUCTION_LENGTH];
    const char *inputFile = "program.alp";

    // Load the ALP program into memory
    int instructionCount = loadALP(inputFile, memory);
    if (instructionCount == -1) {
        return 1;
    }

    // Display the loaded instructions in memory
    displayMemory(memory, instructionCount);

    return 0;
}
/*
MOV A, B
ADD A, #10
SUB B, C
MUL A, B
HLT

*/