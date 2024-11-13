*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

#define FIFO_NAME "myfifo"

void process_management();
void file_management();
void information_management();
void communication_management();

int main(){
    int choice;
    do{
    printf(" SYSTEM CALLS MENUE");
     printf("1.Process Management");
      printf("2.File amanegement");
       printf("3.Information Management");
        printf("4.Communication management");
         printf("5.Exit\n");
         printf("Enter Your Choice(1-5)");
         scanf("%d",&choice);

         switch(choice){
            case 1:
            process_management();
            break;
            case 2:
            file_management();
            break;
            case 3:
            information_management();
            break;
            case 4:
            communication_management();
            break;
            case 5:
            printf("exiting from program");
            break;
            default:
            printf("Invalid Input");



}
while(choice != 5){
    return 0;
}
void process_management(){
    int choice;
    pid_t pid;
     printf("\n--- Process Management ---\n");
    printf("1. fork()\n");
    printf("2. getpid() and getppid()\n");
    printf("3. wait()\n");
    printf("4. execl()\n");
    printf("5. exit()\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
        pid = fork();
        if(pid == 0){
            printf("child process with (PID:%d)",getpid());
            exit(1);
        }
        else if(pid > 0 ){
            printf("Parent process with (PID:%d)",getpid());
            exit(1);
        }
        else{
            printf("fork failed");
        }
        break;
        case 2:
        pid = fork();
        if(pid == 0){
            printf("child process with (PID:%d)",getpid());
            exit(1);
        }
        else if(pid > 0 ){
            printf("child process with (PID:%d)",getpid());
            exit(1);
        }


    }
}
}*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_NAME "myfifo"

void process_management_menu();
void file_management_menu();
void info_management_menu();
void communication_management_menu();

int main() {
    int choice;

    do {
        printf("\n--- System Call Menu ---\n");
        printf("1. Process Management\n");
        printf("2. File Management\n");
        printf("3. Information Management\n");
        printf("4. Communication Management\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                process_management_menu();
                break;
            case 2:
                file_management_menu();
                break;
            case 3:
                info_management_menu();
                break;
            case 4:
                communication_management_menu();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to demonstrate process management system calls
void process_management_menu() {
    int choice;
    pid_t pid;

    printf("\n--- Process Management ---\n");
    printf("1. fork()\n");
    printf("2. getpid() and getppid()\n");
    printf("3. wait()\n");
    printf("4. execl()\n");
    printf("5. exit()\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            pid = fork();
            if (pid == 0) {
                printf("Child process (PID: %d) created successfully.\n", getpid());
                exit(0);
            } else if (pid > 0) {
                printf("Parent process (PID: %d) has child process (PID: %d).\n", getpid(), pid);
            } else {
                perror("fork failed");
            }
            break;
        case 2:
            printf("Process ID: %d, Parent Process ID: %d\n", getpid(), getppid());
            break;
        case 3:
            pid = fork();
            if (pid == 0) {
                printf("Child process (PID: %d) running...\n", getpid());
                sleep(2);
                exit(0);
            } else if (pid > 0) {
                printf("Parent process waiting for child to finish...\n");
                wait(NULL);
                printf("Child process finished.\n");
            } else {
                perror("fork failed");
            }
            break;
        case 4:
            printf("Running ls command using execl()\n");
            execl("/bin/ls", "ls", "-l", NULL);
            perror("execl failed");
            break;
        case 5:
            printf("Exiting process using exit()\n");
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Function to demonstrate file management system calls
void file_management_menu() {
    int choice, fd;
    char buffer[100];
    struct stat fileStat;

    printf("\n--- File Management ---\n");
    printf("1. open(), read(), write(), close()\n");
    printf("2. stat()\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fd = open("testfile.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
            if (fd == -1) {
                perror("open failed");
                return;
            }
            printf("Writing to file...\n");
            write(fd, "Hello, File Management!", 23);
            lseek(fd, 0, SEEK_SET); // Move to the beginning of the file
            printf("Reading from file...\n");
            read(fd, buffer, 23);
            buffer[23] = '\0';
            printf("Data read from file: %s\n", buffer);
            close(fd);
            break;
        case 2:
            if (stat("testfile.txt", &fileStat) < 0) {
                perror("stat failed");
                return;
            }
            printf("File Size: %ld bytes\n", fileStat.st_size);
            printf("Number of Links: %ld\n", fileStat.st_nlink);
            printf("File inode: %ld\n", fileStat.st_ino);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Function to demonstrate information management system calls
void info_management_menu() {
    printf("\n--- Information Management ---\n");
    printf("Sleeping for 3 seconds...\n");
    sleep(3);
    printf("Awake now!\n");
}

// Function to demonstrate communication management system calls
void communication_management_menu() {
    int choice;
    int fd[2];
    char write_msg[] = "Hello from parent!";
    char read_msg[100];
    pid_t pid;

    printf("\n--- Communication Management ---\n");
    printf("1. pipe()\n");
    printf("2. FIFO (named pipe)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (pipe(fd) == -1) {
                perror("pipe failed");
                return;
            }
            pid = fork();
            if (pid == 0) {
                close(fd[1]); // Close unused write end
                read(fd[0], read_msg, sizeof(read_msg));
                printf("Child received: %s\n", read_msg);
                close(fd[0]);
                exit(0);
            } else if (pid > 0) {
                close(fd[0]); // Close unused read end
                write(fd[1], write_msg, strlen(write_msg) + 1);
                close(fd[1]);
                wait(NULL);
            } else {
                perror("fork failed");
            }
            break;
        case 2:
            // Create FIFO if it does not exist
            if (mkfifo(FIFO_NAME, 0666) == -1) {
                perror("mkfifo failed");
                return;
            }
            pid = fork();
            if (pid == 0) {
                int fd_fifo = open(FIFO_NAME, O_RDONLY);
                read(fd_fifo, read_msg, sizeof(read_msg));
                printf("Child received from FIFO: %s\n", read_msg);
                close(fd_fifo);
                exit(0);
            } else if (pid > 0) {
                int fd_fifo = open(FIFO_NAME, O_WRONLY);
                write(fd_fifo, write_msg, strlen(write_msg) + 1);
                close(fd_fifo);
                wait(NULL);
            } else {
                perror("fork failed");
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
}
