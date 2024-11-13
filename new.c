// bin bash with ALP 
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


#!/bin/bash

factorial_if_else(){
    echo -n "enter a number"
    read num
    fact=1
    if [$num -lt 0];
    then
    echo "factorial not exist for negative integers"
    elif [$num -eq 0];
    then
    echo " factorial of 0 is 1"
    else 
    for((i=0;i<=num;i++))
    do
    fact=$((fact*i))
    done
    echo "factorial of $num is $fact"
    fi

}

prime_while() {
    echo -n "Enter a number: "
    read num
    if [ $num -le 1 ]; then
        echo "$num is not a prime number."
        return
    fi

    i=2
    while [ $i -le $(($num / 2)) ]
    do
        if [ $(($num % i)) -eq 0 ]; then
            echo "$num is not a prime number."
            return
        fi
        i=$(($i + 1))
    done
    echo "$num is a prime number."
}


sum_for() {
    echo -n "Enter the limit: "
    read limit
    sum=0
    for ((i=1; i<=limit; i++))
    do
        sum=$((sum + i))
    done
    echo "Sum of numbers from 1 to $limit is $sum."
}


countdown_until() {
    echo -n "Enter a number: "
    read num
    until [ $num -lt 1 ]
    do
        echo "$num"
        num=$((num - 1))
    done
    echo "Countdown finished!"
}


show_menu() {
    echo "1) Factorial (using if-else)"
    echo "2) Prime Check (using while loop)"
    echo "3) Sum of Numbers (using for loop)"
    echo "4) Countdown (using until loop)"
    echo "5) Exit"
    echo -n "Enter your choice: "
    read choice
}

while true
do
    show_menu
    case $choice in
        1) factorial_if_else ;;
        2) prime_while ;;
        3) sum_for ;;
        4) countdown_until ;;
        5) exit ;;
        *) echo "Invalid choice! Please try again." ;;
    esac
    echo