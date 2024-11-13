// copy content line by line 


/*#include <stdio.h>
#include <stdlib.h>

void copyFileCharacterByCharacter(const char *sourceFile, const char *destFile) {
    FILE *source = fopen(sourceFile, "r");
    FILE *dest = fopen(destFile, "w");

    if (source == NULL || dest == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(source)) != EOF) {  // Read each character until end of file
        fputc(ch, dest);  // Write each character to destination
    }

    printf("File copied successfully, character by character.\n");

    fclose(source);
    fclose(dest);
}

int main() {
    const char *sourceFile = "source.txt";
    const char *destFile = "destination.txt";

    copyFileCharacterByCharacter(sourceFile, destFile);

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

void printFileCharacterByCharacter(const char *sourceFile) {
    FILE *source = fopen(sourceFile, "r");

    if (source == NULL) {
        printf("Error opening source file.\n");
        exit(1);
    }

    char ch;
    // Read and print each character to the terminal
    while ((ch = fgetc(source)) != EOF) {  
        putchar(ch);  // Print each character to the terminal
    }

    fclose(source);
}

int main() {
    const char *sourceFile = "source.txt";

    printFileCharacterByCharacter(sourceFile);

    return 0;
}
