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

// 2
// various system calls 

#include<stdio.h>
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

//3
// shortest job in cpu schedulling
#include <stdio.h>
#include <stdbool.h>


struct Process {
    int pid;          // Process ID
    int arrivalTime;
    int burstTime;
    int remainingTime; // For preemptive SJF
    int finishTime;
    int turnAroundTime;
    int waitingTime;
    bool isCompleted;
};


// Function for Non-Preemptive SJF
void sjfNonPreemptive(struct Process processes[], int n) {
    int currentTime = 0, completed = 0;


    while (completed < n) {
        int minIndex = -1;
        int minBurstTime = 1e9;


        // Select the process with the smallest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (!processes[i].isCompleted && processes[i].arrivalTime <= currentTime &&
                processes[i].burstTime < minBurstTime) {
                minBurstTime = processes[i].burstTime;
                minIndex = i;
            }
        }


        if (minIndex == -1) {
            currentTime++;
        } else {
            // Calculate the finish time, turnaround time, and waiting time
            processes[minIndex].finishTime = currentTime + processes[minIndex].burstTime;
            processes[minIndex].turnAroundTime = processes[minIndex].finishTime - processes[minIndex].arrivalTime;
            processes[minIndex].waitingTime = processes[minIndex].turnAroundTime - processes[minIndex].burstTime;
            processes[minIndex].isCompleted = true;


            currentTime = processes[minIndex].finishTime;
            completed++;
        }
    }
}


// Function for Preemptive SJF
void sjfPreemptive(struct Process processes[], int n) {
    int currentTime = 0, completed = 0;
    int minIndex = -1;
    int minRemainingTime = 1e9;


    while (completed < n) {
        minIndex = -1;
        minRemainingTime = 1e9;


        // Select the process with the smallest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted &&
                processes[i].remainingTime < minRemainingTime) {
                minRemainingTime = processes[i].remainingTime;
                minIndex = i;
            }
        }


        if (minIndex != -1) {
            processes[minIndex].remainingTime--;
            currentTime++;


            // If process is completed
            if (processes[minIndex].remainingTime == 0) {
                processes[minIndex].finishTime = currentTime;
                processes[minIndex].turnAroundTime = processes[minIndex].finishTime - processes[minIndex].arrivalTime;
                processes[minIndex].waitingTime = processes[minIndex].turnAroundTime - processes[minIndex].burstTime;
                processes[minIndex].isCompleted = true;
                completed++;
            }
        } else {
            currentTime++;
        }
    }
}


void displayResults(struct Process processes[], int n) {
    printf("PID\tArrival\tBurst\tFinish\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n",
               processes[i].pid,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].finishTime,
               processes[i].turnAroundTime,
               processes[i].waitingTime);
    }


    float totalTurnAroundTime = 0, totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalTurnAroundTime += processes[i].turnAroundTime;
        totalWaitingTime += processes[i].waitingTime;
    }


    printf("Average Turnaround Time: %.2f\n", totalTurnAroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
}


int main() {
    int n, choice;
    printf("Enter the number of processes: ");
    scanf("%d", &n);


    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].isCompleted = false;
    }


    printf("Choose Scheduling:\n1. Non-Preemptive SJF\n2. Preemptive SJF\n");
    scanf("%d", &choice);


    if (choice == 1) {
        sjfNonPreemptive(processes, n);
    } else if (choice == 2) {
        sjfPreemptive(processes, n);
    } else {
        printf("Invalid choice!\n");
        return 0;
    }


    displayResults(processes, n);
    return 0;
}


// 4
// round robin in CPU schedulling 
#include <stdio.h>


struct Process {
    int pid;           // Process ID
    int arrivalTime;   // Arrival time
    int burstTime;     // Burst time
    int remainingTime; // Remaining burst time
    int finishTime;    // Finish time
    int turnAroundTime; // Turnaround time
    int waitingTime;   // Waiting time
};


void roundRobin(struct Process processes[], int n, int quantum) {
    int currentTime = 0;
    int completed = 0;
    int timeQuantum = quantum;


    while (completed < n) {
        int done = 1;


        for (int i = 0; i < n; i++) {
            // Check if process has remaining time and has arrived
            if (processes[i].remainingTime > 0 && processes[i].arrivalTime <= currentTime) {
                done = 0;


                // If remaining time is less than or equal to time quantum, process will finish
                if (processes[i].remainingTime <= timeQuantum) {
                    currentTime += processes[i].remainingTime;
                    processes[i].finishTime = currentTime;
                    processes[i].turnAroundTime = processes[i].finishTime - processes[i].arrivalTime;
                    processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
                    processes[i].remainingTime = 0;
                    completed++;
                } else {
                    // Process runs for the time quantum
                    processes[i].remainingTime -= timeQuantum;
                    currentTime += timeQuantum;
                }
            }
        }


        // If all processes are done
        if (done) {
            currentTime++;
        }
    }
}


void displayResults(struct Process processes[], int n) {
    printf("PID\tArrival\tBurst\tFinish\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n",
               processes[i].pid,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].finishTime,
               processes[i].turnAroundTime,
               processes[i].waitingTime);
    }


    float totalTurnAroundTime = 0, totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalTurnAroundTime += processes[i].turnAroundTime;
        totalWaitingTime += processes[i].waitingTime;
    }


    printf("Average Turnaround Time: %.2f\n", totalTurnAroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
}


int main() {
    int n, quantum;


    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];


    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }


    printf("Enter the time quantum: ");
    scanf("%d", &quantum);


    roundRobin(processes, n, quantum);
    displayResults(processes, n);


    return 0;
}
 // 5
 // readre writer problem 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


// Shared data and synchronization variables
int shared_data = 0;
int reader_count = 0;
pthread_mutex_t resource_mutex;      // Mutex for exclusive access to shared data
pthread_mutex_t reader_count_mutex;   // Mutex for protecting reader count
int max_operations = 5; // Number of iterations for readers and writers


// Reader function
void* reader(void* arg) {
    int reader_id = *((int*)arg);
    free(arg);
    int read_count = 0;


    while (read_count < max_operations) { 
        // Entry section for reader
        pthread_mutex_lock(&reader_count_mutex);
        reader_count++;
        if (reader_count == 1) {
            pthread_mutex_lock(&resource_mutex); // First reader locks the resource
        }
        pthread_mutex_unlock(&reader_count_mutex);


        // Reading section
        printf("Reader %d is reading the shared data: %d\n", reader_id, shared_data);


        // Exit section for reader
        pthread_mutex_lock(&reader_count_mutex);
        reader_count--;
        if (reader_count == 0) {
            pthread_mutex_unlock(&resource_mutex); // Last reader unlocks the resource
        }
        pthread_mutex_unlock(&reader_count_mutex);


        read_count++; // Increment read count
    }


    return NULL;
}


// Writer function
void* writer(void* arg) {
    int writer_id = *((int*)arg);
    free(arg);
    int write_count = 0;


    while (write_count < max_operations) { 
        pthread_mutex_lock(&resource_mutex);  // Writer locks the resource
        shared_data++;
        printf("Writer %d updated shared data to: %d\n", writer_id, shared_data);
        pthread_mutex_unlock(&resource_mutex);  // Writer releases the resource
        
        write_count++; // Increment write count
    }


    return NULL;
}


int main() {
    pthread_t readers[5], writers[2];
    pthread_mutex_init(&resource_mutex, NULL);
    pthread_mutex_init(&reader_count_mutex, NULL);


    // Create reader threads
    for (int i = 0; i < 5; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&readers[i], NULL, reader, id);
    }


    // Create writer threads
    for (int i = 0; i < 2; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&writers[i], NULL, writer, id);
    }


    // Wait for threads to complete
    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }


    // Destroy mutexes
    pthread_mutex_destroy(&resource_mutex);
    pthread_mutex_destroy(&reader_count_mutex);


    return 0;
}

//6
// reader writer using threads and semaphores 

import java.util.concurrent.Semaphore;


class ReaderWriter {
  private int readCount = 0; // Count of active readers
  private final Semaphore mutex; // Mutex to protect readCount
  private final Semaphore writeLock; // WriteLock to ensure only one writer


  public ReaderWriter() {
    mutex = new Semaphore(1); // Binary semaphore for reader count update
    writeLock = new Semaphore(1); // Binary semaphore for writer synchronization
  }


  // Reader class
  class Reader implements Runnable {
    private final String readerName;


    Reader(String name) {
      this.readerName = name;
    }


    @Override
    public void run() {
      try {
        // Entry Section for Reader
        mutex.acquire(); // Protecting readCount
        readCount++;
        if (readCount == 1) {
          writeLock.acquire(); // First reader locks the writeLock
        }
        mutex.release(); // Release mutex after updating readCount


        // Critical Section for Reader (Reading)
        System.out.println(readerName + " is READING");


        // Simulate reading with sleep
        Thread.sleep(1000);


        // Exit Section for Reader
        mutex.acquire();
        readCount--;
        if (readCount == 0) {
          writeLock.release(); // Last reader releases the writeLock
        }
        mutex.release();


        System.out.println(readerName + " has FINISHED READING");


      } catch (InterruptedException e) {
        System.out.println(e.getMessage());
      }
    }
  }


  // Writer class
  class Writer implements Runnable {
    private final String writerName;


    Writer(String name) {
      this.writerName = name;
    }


    @Override
    public void run() {
      try {
        // Entry Section for Writer
        writeLock.acquire(); // Writer acquires writeLock


        // Critical Section for Writer (Writing)
        System.out.println(writerName + " is WRITING");


        // Simulate writing with sleep
        Thread.sleep(1500);


        // Exit Section for Writer
        writeLock.release();


        System.out.println(writerName + " has FINISHED WRITING");


      } catch (InterruptedException e) {
        System.out.println(e.getMessage());
      }
    }
  }


  public static void main(String[] args) {
    ReaderWriter rw = new ReaderWriter();


    // Creating reader and writer threads
    Thread reader1 = new Thread(rw.new Reader("Reader 1"));
    Thread reader2 = new Thread(rw.new Reader("Reader 2"));
    Thread writer1 = new Thread(rw.new Writer("Writer 1"));
    Thread writer2 = new Thread(rw.new Writer("Writer 2"));


    // Start threads
    reader1.start();
    writer1.start();
    reader2.start();
    writer2.start();
  }
}

// producer consumer problem 


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


#define BUFFER_SIZE 5


int buffer[BUFFER_SIZE];
int count = 0;
pthread_mutex_t mutex;
pthread_cond_t not_full, not_empty;


void* producer(void* arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        item = rand() % 100;
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE)
            pthread_cond_wait(&not_full, &mutex);
        buffer[count++] = item;
        printf("Producer produced: %d\n", item);
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
        // Removed sleep(1); // No sleep for faster execution
    }
    return NULL;
}


void* consumer(void* arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0)
            pthread_cond_wait(&not_empty, &mutex);
        item = buffer[--count];
        printf("Consumer consumed: %d\n", item);
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);
        // Removed sleep(1); // No sleep for faster execution
    }
    return NULL;
}


int main() {
    pthread_t prod_thread, cons_thread;


    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);


    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);


    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);


    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);


    return 0;
}


// priority schedulling in CPU 
#include <stdio.h>
#include <stdbool.h>


struct Process {
    int pid;          // Process ID
    int arrivalTime;
    int burstTime;
    int remainingTime; // For preemptive scheduling
    int priority;
    int finishTime;
    int turnAroundTime;
    int waitingTime;
    bool isCompleted;
};


// Function for Non-Preemptive Priority Scheduling
void priorityNonPreemptive(struct Process processes[], int n) {
    int currentTime = 0, completed = 0;


    while (completed < n) {
        int minIndex = -1;
        int highestPriority = 1e9;


        // Select the process with the highest priority that has arrived
        for (int i = 0; i < n; i++) {
            if (!processes[i].isCompleted && processes[i].arrivalTime <= currentTime &&
                processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                minIndex = i;
            }
        }


        if (minIndex == -1) {
            currentTime++;
        } else {
            // Calculate the finish time, turnaround time, and waiting time
            processes[minIndex].finishTime = currentTime + processes[minIndex].burstTime;
            processes[minIndex].turnAroundTime = processes[minIndex].finishTime - processes[minIndex].arrivalTime;
            processes[minIndex].waitingTime = processes[minIndex].turnAroundTime - processes[minIndex].burstTime;
            processes[minIndex].isCompleted = true;


            currentTime = processes[minIndex].finishTime;
            completed++;
        }
    }
}


// Function for Preemptive Priority Scheduling
void priorityPreemptive(struct Process processes[], int n) {
    int currentTime = 0, completed = 0;


    while (completed < n) {
        int minIndex = -1;
        int highestPriority = 1e9;


        // Select the process with the highest priority that has arrived
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted &&
                processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                minIndex = i;
            }
        }


        if (minIndex != -1) {
            // Process one unit of the burst time
            processes[minIndex].remainingTime--;
            currentTime++;


            // If process is completed
            if (processes[minIndex].remainingTime == 0) {
                processes[minIndex].finishTime = currentTime;
                processes[minIndex].turnAroundTime = processes[minIndex].finishTime - processes[minIndex].arrivalTime;
                processes[minIndex].waitingTime = processes[minIndex].turnAroundTime - processes[minIndex].burstTime;
                processes[minIndex].isCompleted = true;
                completed++;
            }
        } else {
            currentTime++;
        }
    }
}


void displayResults(struct Process processes[], int n) {
    printf("PID\tArrival\tBurst\tPriority\tFinish\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t\t%d\n",
               processes[i].pid,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].priority,
               processes[i].finishTime,
               processes[i].turnAroundTime,
               processes[i].waitingTime);
    }


    float totalTurnAroundTime = 0, totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalTurnAroundTime += processes[i].turnAroundTime;
        totalWaitingTime += processes[i].waitingTime;
    }


    printf("Average Turnaround Time: %.2f\n", totalTurnAroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
}


int main() {
    int n, choice;
    printf("Enter the number of processes: ");
    scanf("%d", &n);


    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time, burst time, and priority for process %d: ", processes[i].pid);
        scanf("%d %d %d", &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].isCompleted = false;
    }


    printf("Choose Scheduling:\n1. Non-Preemptive Priority\n2. Preemptive Priority\n");
    scanf("%d", &choice);


    if (choice == 1) {
        priorityNonPreemptive(processes, n);
    } else if (choice == 2) {
        priorityPreemptive(processes, n);
    } else {
        printf("Invalid choice!\n");
        return 0;
    }


    displayResults(processes, n);
    return 0;
}

// LRU in page replacement
#include <stdio.h>


#define MAX_FRAMES 10


int findLRU(int frames[], int time[], int frameCount) {
    int min = time[0], minIndex = 0;
    for (int i = 1; i < frameCount; i++) {
        if (time[i] < min) {
            min = time[i];
            minIndex = i;
        }
    }
    return minIndex; // Return the index of the LRU page
}


int isPageInFrames(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return 1; // Page found in frames
        }
    }
    return 0; // Page not found
}


int main() {
    int frameCount, pageCount;
    int pageFaults = 0;


    // Input: Number of frames and number of pages in the reference string
    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);


    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &pageCount);


    int pages[pageCount];
    printf("Enter the reference string (space-separated): ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }


    int frames[MAX_FRAMES];
    int time[MAX_FRAMES]; // Array to keep track of the last used time of each frame
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1; // Initialize frames as empty
        time[i] = 0; // Initialize the last used time
    }


    // Processing each page in the reference string
    for (int i = 0; i < pageCount; i++) {
        int currentPage = pages[i];


        // Check if the current page is already in the frames
        if (!isPageInFrames(frames, frameCount, currentPage)) {
            // Page fault occurs as the page is not in frames
            int lruIndex = findLRU(frames, time, frameCount); // Find the index of the LRU page
            frames[lruIndex] = currentPage; // Replace the LRU page with the current page
            pageFaults++; // Increment page faults
        }


        // Update the time of the current page
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                time[j] = i; // Update the last used time for the current page
                break;
            }
        }
    }


    printf("\nTotal Page Faults: %d\n", pageFaults);


    return 0;
}

// fifo page replacement 
#include <stdio.h>


#define MAX_FRAMES 10


int isPageInFrames(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return 1; // Page found in frames
        }
    }
    return 0; // Page not found
}


int main() {
    int frameCount, pageCount;
    int pageFaults = 0;
    int nextFrameToReplace = 0; // To keep track of which frame to replace next


    // Input: Number of frames and number of pages in the reference string
    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);


    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &pageCount);


    int pages[pageCount];
    printf("Enter the reference string (space-separated): ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }


    int frames[MAX_FRAMES];
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1; // Initialize frames as empty
    }


    // Processing each page in the reference string
    for (int i = 0; i < pageCount; i++) {
        int currentPage = pages[i];


        // Check if the current page is already in the frames
        if (!isPageInFrames(frames, frameCount, currentPage)) {
            // Page fault occurs as the page is not in frames
            frames[nextFrameToReplace] = currentPage; // Replace the page at nextFrameToReplace
            pageFaults++; // Increment page faults
            nextFrameToReplace = (nextFrameToReplace + 1) % frameCount; // Move to the next frame
        }
    }


    printf("\nTotal Page Faults: %d\n", pageFaults);


    return 0;
}
 // optimal page replacement 
#include <stdio.h>


#define MAX_FRAMES 10


int findOptimal(int frames[], int frameCount, int pages[], int pageCount, int currentIndex) {
    int farthest = currentIndex, indexToReplace = -1;


    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = currentIndex; j < pageCount; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    indexToReplace = i;
                }
                break;
            }
        }
        // If the frame is never going to be used again
        if (j == pageCount) {
            return i; // Replace this frame
        }
    }
   
    // If all pages are used in the future, replace the one that is used the farthest in the future
    return (indexToReplace != -1) ? indexToReplace : 0;
}


int isPageInFrames(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return 1; // Page found in frames
        }
    }
    return 0; // Page not found
}


int main() {
    int frameCount, pageCount;
    int pageFaults = 0;


    // Input: Number of frames and number of pages in the reference string
    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);


    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &pageCount);


    int pages[pageCount];
    printf("Enter the reference string (space-separated): ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }


    int frames[MAX_FRAMES];
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1; // Initialize frames as empty
    }


    // Processing each page in the reference string
    for (int i = 0; i < pageCount; i++) {
        int currentPage = pages[i];


        // Check if the current page is already in the frames
        if (!isPageInFrames(frames, frameCount, currentPage)) {
            // Page fault occurs as the page is not in frames
            int indexToReplace = findOptimal(frames, frameCount, pages, pageCount, i); // Find the optimal frame to replace
            frames[indexToReplace] = currentPage; // Replace the optimal frame with the current page
            pageFaults++; // Increment page faults
        }
    }


    printf("\nTotal Page Faults: %d\n", pageFaults);


    return 0;
}


// Operand error 
#include<stdio.h>
#include<stdbool.h>

typedef struct {
    char opcode[10];
    int operand1;
    int operand2;

}Instruction;

bool hasOperandError(Instruction inst){
    return inst.operand1<0 || inst.operand2<0;
}

void raiseError(Instruction inst){
    printf("Operand error for opcode %s and for the operands %d %d : \n",inst.opcode,inst.operand1,inst.operand2);
}

void checkOperandError(Instruction job[],int jobSize){
    for(int i=0;i<jobSize;i++){
    if(hasOperandError(job[i])){
        raiseError(job[i]);
    }
    }
}
int main(){
    Instruction job[] = {
        {"ADD", 10, 20},
        {"SUB", -5, 15},      // Operand error
        {"MOV", 30, 40},
        {"MUL", 10, -1},      // Operand error
        {"DIV", 25, 5}
    };
    printf("Checking for oprand error : ");
    checkOperandError(job,5);
    return 0;

    // Operand error 
#include<stdio.h>
#include<stdbool.h>

typedef struct {
    char opcode[10];
    int operand1;
    int operand2;

}Instruction;

bool hasOperandError(Instruction inst){
    return inst.operand1<0 || inst.operand2<0;
}

void raiseError(Instruction inst){
    printf("Operand error for opcode %s and for the operands %d %d : \n",inst.opcode,inst.operand1,inst.operand2);
}

void checkOperandError(Instruction job[],int jobSize){
    for(int i=0;i<jobSize;i++){
    if(hasOperandError(job[i])){
        raiseError(job[i]);
    }
    }
}
int main(){
    Instruction job[] = {
        {"ADD", 10, 20},
        {"SUB", -5, 15},      // Operand error
        {"MOV", 30, 40},
        {"MUL", 10, -1},      // Operand error
        {"DIV", 25, 5}
    };
    printf("Checking for oprand error : ");
    checkOperandError(job,5);
    return 0;
    // Opcode Error 
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const char *validOpcodes[] = {"ADD","SUB","MULT","DIV","MOV"};
const int validOpcodeCount = 5;

bool isValidOpcode(char *opcode){
    for(int i=0 ; i<validOpcodeCount;i++){
        if(strcmp(opcode,validOpcodes[i])==0){
            return true;

        }
    }
    return false;
}

void raiseError(char *opcode){
    
        printf("opcode error for the opcode : %s\n", opcode);
    
}

void checkOpcodeErrors(char job[][10], int jobSize){
    for(int i=0 ; i<jobSize ; i++){
        if(!isValidOpcode(job[i])){
            raiseError(job[i]);
        }

    }
}
int main(){
char job[][10] = {
        "ADD",
        "MUL",
        "XYZ",  // Invalid opcode
        "MOV",
        "SUB"
    };

    printf("Checking for opcode error :\n");
    checkOpcodeErrors(job,5);
    return 0;

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

    //  matrix multiplication 


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// Define the dimensions of the matrices
#define M 3  
#define N 3
#define P 3  


// Matrices
int A[M][N];
int B[N][P];
int C[M][P];


// Structure to pass data to threads
typedef struct {
    int row;
    int col;
} thread_data_t;


// Thread function to perform matrix multiplication for a specific element
void* multiply(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;
    int row = data->row;
    int col = data->col;
    C[row][col] = 0;  


    // Perform the matrix multiplication for a single element
    for (int k = 0; k < N; k++) {
        C[row][col] += A[row][k] * B[k][col];
    }


    pthread_exit(NULL);
}


int main() {
    pthread_t threads[M * P];        
    thread_data_t thread_data[M * P];
    // Initialize matrices A and B
    printf("Matrix A:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }


    printf("\nMatrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = rand() % 10;  // Random numbers between 0 and 9
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }




    int thread_idx = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            thread_data[thread_idx].row = i;
            thread_data[thread_idx].col = j;
            pthread_create(&threads[thread_idx], NULL, multiply, (void*)&thread_data[thread_idx]);
            thread_idx++;
        }
    }


    // Join all threads
    for (int i = 0; i < M * P; i++) {
        pthread_join(threads[i], NULL);
    }


    // Display the result matrix C
    printf("\nResultant Matrix C (A * B):\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }


    return 0;
}
// fisrt come first serve for CPU 
#include <stdio.h>


struct Process {
    int pid;       // Process ID
    int arrivalTime;
    int burstTime;
    int finishTime;
    int turnAroundTime;
    int waitingTime;
};


void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;


    for (int i = 0; i < n; i++) {
        // If the process arrives after the current time, update the current time to the arrival time of the process
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }


        // Finish time is the current time plus the burst time
        processes[i].finishTime = currentTime + processes[i].burstTime;


        // Turnaround time is finish time minus arrival time
        processes[i].turnAroundTime = processes[i].finishTime - processes[i].arrivalTime;


        // Waiting time is turnaround time minus burst time
        processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;


        // Update current time to finish time of the current process
        currentTime = processes[i].finishTime;
    }
}


void displayResults(struct Process processes[], int n) {
    printf("PID\tArrival\tBurst\tFinish\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t\t%d\n",
               processes[i].pid,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].finishTime,
               processes[i].turnAroundTime,
               processes[i].waitingTime);
    }


    float totalTurnAroundTime = 0, totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalTurnAroundTime += processes[i].turnAroundTime;
        totalWaitingTime += processes[i].waitingTime;
    }


    printf("Average Turnaround Time: %.2f\n", totalTurnAroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
}


int main() {
    int n;


    printf("Enter the number of processes: ");
    scanf("%d", &n);


    struct Process processes[n];


    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
    }


    // Sort processes by arrival time (FCFS scheduling)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrivalTime > processes[j].arrivalTime) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }


    calculateTimes(processes, n);
    displayResults(processes, n);


    return 0;
}


// disk sjfs 
// for stfs disk 
#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the closest request
int find_closest_request(int current_position, int requests[], int n, int visited[]) {
    int min_seek_time = 10000;  // A large number (initial seek time)
    int closest_index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int seek_time = abs(requests[i] - current_position);
            if (seek_time < min_seek_time) {
                min_seek_time = seek_time;
                closest_index = i;
            }
        }
    }
    return closest_index;
}

// Function to calculate total seek time and print the request sequence
void SSTF_Disk_Scheduling(int start, int requests[], int n) {
    int total_seek_time = 0;  // Initialize total seek time
    int visited[n];           // Array to track visited requests
    for (int i = 0; i < n; i++) {
        visited[i] = 0;        // Initialize all requests as unvisited
    }

    int current_position = start;  // Start at the initial position
    int count = 0;                 // To track the number of processed requests

    // Print the table header
    printf("Track No. | Disk Head Position | Seek Time\n");
    printf("-------------------------------------------\n");

    // Process each request using SSTF (Shortest Seek Time First)
    while (count < n) {
        int closest_index = find_closest_request(current_position, requests, n, visited);
        int seek_time = abs(requests[closest_index] - current_position); // Calculate seek time
        total_seek_time += seek_time; // Accumulate seek time
        current_position = requests[closest_index]; // Update current position
        visited[closest_index] = 1; // Mark the current request as visited
        count++;

        // Print the current request and its seek time
        printf("%9d | %17d | %9d\n", requests[closest_index], current_position, seek_time);
    }

    // Print the total seek time
    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int start;               // Starting position of the disk head
    int n;                   // Number of disk requests

    // Input: Starting position of disk head and number of requests
    printf("Enter the starting position of the disk head: ");
    scanf("%d", &start);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n]; // Array to store the disk requests

    // Input: Disk requests (track numbers)
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Call SSTF Disk Scheduling function to calculate and print results
    SSTF_Disk_Scheduling(start, requests, n);

    return 0;
}

// disk scan 
#include <stdio.h>
#include <stdlib.h>


void SCAN(int head, int requests[], int n, int disk_size, int direction) {
    int total_seek_time = 0;
    int temp, i, j;


    // Sort the request array
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }


    // Find the position of the head in the sorted request array
    int pos = 0;
    for (i = 0; i < n; i++) {
        if (head < requests[i]) {
            pos = i;
            break;
        }
    }


    printf("\nSCAN Disk Scheduling\n");
    printf("Initial Head Position: %d\n", head);
    printf("Direction: %s\n", direction == 1 ? "Right" : "Left");


    printf("\nRequest\tCurrent Head Position\tSeek Time\n");
    printf("-------\t----------------------\t---------\n");


    // Serve requests based on the direction
    if (direction == 1) { // Moving towards the right
        for (i = pos; i < n; i++) {
            int seek_time = abs(requests[i] - head);
            total_seek_time += seek_time;
            printf("%d\t\t%d\t\t\t%d\n", requests[i], head, seek_time);
            head = requests[i];
        }
        // Go to the end of the disk if necessary
        if (head != disk_size - 1) {
            int seek_time = abs((disk_size - 1) - head);
            total_seek_time += seek_time;
            printf("%d\t\t%d\t\t\t%d\n", disk_size - 1, head, seek_time);
            head = disk_size - 1;
        }
        // Reverse direction and continue serving requests to the left
        for (i = pos - 1; i >= 0; i--) {
            int seek_time = abs(requests[i] - head);
            total_seek_time += seek_time;
            printf("%d\t\t%d\t\t\t%d\n", requests[i], head, seek_time);
            head = requests[i];
        }
    } else { // Moving towards the left
        for (i = pos - 1; i >= 0; i--) {
            int seek_time = abs(requests[i] - head);
            total_seek_time += seek_time;
            printf("%d\t\t%d\t\t\t%d\n", requests[i], head, seek_time);
            head = requests[i];
        }
        // Go to the start of the disk if necessary
        if (head != 0) {
            int seek_time = abs(head - 0);
            total_seek_time += seek_time;
            printf("%d\t\t%d\t\t\t%d\n", 0, head, seek_time);
            head = 0;
        }
        // Reverse direction and continue serving requests to the right
        for (i = pos; i < n; i++) {
            int seek_time = abs(requests[i] - head);
            total_seek_time += seek_time;
            printf("%d\t\t%d\t\t\t%d\n", requests[i], head, seek_time);
            head = requests[i];
        }
    }


    printf("\nTotal Seek Time: %d\n", total_seek_time);
}


int main() {
    int n, head, disk_size, direction;


    // Input number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);


    int requests[n];


    // Input the disk requests
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }


    // Input initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);


    // Input the size of the disk
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);


    // Input direction (1 for right, 0 for left)
    printf("Enter the initial direction (1 for right, 0 for left): ");
    scanf("%d", &direction);


    // Call the SCAN function to calculate seek time
    SCAN(head, requests, n, disk_size, direction);


    return 0;
}
// second one 
// SCAN disk 
#include <stdio.h>
#include <stdlib.h>

// Function to simulate SCAN Disk Scheduling
void SCAN_Disk_Scheduling(int start, int requests[], int n, int max_track) {
    int total_seek_time = 0;
    int left[n], right[n];
    int left_count = 0, right_count = 0;

    // Separate requests into left and right of the starting position
    for (int i = 0; i < n; i++) {
        if (requests[i] < start) {
            left[left_count++] = requests[i];
        } else {
            right[right_count++] = requests[i];
        }
    }

    // Sort the left and right requests
    for (int i = 0; i < left_count - 1; i++) {
        for (int j = i + 1; j < left_count; j++) {
            if (left[i] < left[j]) {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }

    for (int i = 0; i < right_count - 1; i++) {
        for (int j = i + 1; j < right_count; j++) {
            if (right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }

    // Calculate total seek time by moving to the left end first, then to the right
    int current_position = start;
    int seek_time = 0;

    // Print the table header
    printf("Track No. | Disk Head Position | Seek Time\n");
    printf("-------------------------------------------\n");

    // Move to the left end and service requests
    for (int i = 0; i < left_count; i++) {
        seek_time = abs(current_position - left[i]);
        total_seek_time += seek_time;
        current_position = left[i];
        printf("%9d | %17d | %9d\n", left[i], current_position, seek_time);
    }

    // Move to the leftmost track (0 or max track) and then move to the right
    seek_time = abs(current_position - 0);
    total_seek_time += seek_time;
    current_position = 0;
    printf("%9d | %17d | %9d\n", 0, current_position, seek_time);

    // Service requests in the right direction
    for (int i = 0; i < right_count; i++) {
        seek_time = abs(current_position - right[i]);
        total_seek_time += seek_time;
        current_position = right[i];
        printf("%9d | %17d | %9d\n", right[i], current_position, seek_time);
    }

    // Print the total seek time
    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int start;               // Starting position of the disk head
    int n;                   // Number of disk requests
    int max_track;           // Maximum track number (total number of tracks)

    // Input: Starting position of disk head, number of requests, and max track number
    printf("Enter the starting position of the disk head: ");
    scanf("%d", &start);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the maximum track number: ");
    scanf("%d", &max_track);

    int requests[n]; // Array to store the disk requests

    // Input: Disk requests (track numbers)
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Call SCAN Disk Scheduling function to calculate and print results
    SCAN_Disk_Scheduling(start, requests, n, max_track);

    return 0;
}

// dining philosopher using threads and semaphores 

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>




#define N 5




sem_t forks[N];




void *philosopher(void *arg) {
    int id = *((int *)arg);




    for (int i = 0; i < 3; i++) {
        printf("Philosopher %d is thinking.\n", id);
        usleep(100000);




        sem_wait(&forks[id]);
        sem_wait(&forks[(id + 1) % N]);




        printf("Philosopher %d is eating.\n", id);
        usleep(100000);




        sem_post(&forks[id]);
        sem_post(&forks[(id + 1) % N]);




        printf("Philosopher %d finished eating.\n", id);
        usleep(100000);
    }
    return NULL;
}




int main() {
    pthread_t philosophers[N];
    int ids[N];




    for (int i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);




    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }




    for (int i = 0; i < N; i++)
        pthread_join(philosophers[i], NULL);




    for (int i = 0; i < N; i++)
        sem_destroy(&forks[i]);




    return 0;
}


// deadlock detecion 
#include <stdio.h>
#include <stdbool.h>


#define MAX_PROCESSES 10
#define MAX_RESOURCES 10


int processes, resources;
int available[MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int request[MAX_PROCESSES][MAX_RESOURCES];


void deadlockDetection() {
    bool finish[MAX_PROCESSES] = {false};
    int work[MAX_RESOURCES];


    // Initialize work as a copy of available resources
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }


    bool deadlock = false;
    int deadlockedProcesses[MAX_PROCESSES];
    int deadlockedCount = 0;


    for (int count = 0; count < processes; count++) {
        bool found = false;


        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                bool canProceed = true;


                // Check if the process's request can be satisfied
                for (int j = 0; j < resources; j++) {
                    if (request[i][j] > work[j]) {
                        canProceed = false;
                        break;
                    }
                }


                // If the request can be satisfied, allocate resources temporarily
                if (canProceed) {
                    for (int j = 0; j < resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }


        // If no process could proceed in this round, break out
        if (!found) {
            break;
        }
    }


    // Check for processes still marked as unfinished
    for (int i = 0; i < processes; i++) {
        if (!finish[i]) {
            deadlockedProcesses[deadlockedCount++] = i;
            deadlock = true;
        }
    }


    if (deadlock) {
        printf("System is in a deadlock state.\n");
        printf("Deadlocked processes: ");
        for (int i = 0; i < deadlockedCount; i++) {
            printf("P%d ", deadlockedProcesses[i]);
        }
        printf("\n");
    } else {
        printf("System is not in a deadlock state.\n");
    }
}


int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &processes);


    printf("Enter the number of resources: ");
    scanf("%d", &resources);


    printf("Enter the available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }


    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }


    printf("Enter the request matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &request[i][j]);
        }
    }


    deadlockDetection();


    return 0;
}

// deadlock avoidance algorithm 
#include <stdio.h>
#include <stdbool.h>


#define MAX_PROCESSES 10
#define MAX_RESOURCES 10


int processes, resources;
int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];


void calculateNeed() {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}


bool isSafeState() {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int safeSequence[MAX_PROCESSES];
    int count = 0;


    // Initialize work as a copy of available resources
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }


    while (count < processes) {
        bool found = false;


        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                bool canAllocate = true;


                for (int j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }


                if (canAllocate) {
                    for (int k = 0; k < resources; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }


        if (!found) {
            printf("System is not in a safe state.\n");
            return false;
        }
    }


    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < processes; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return true;
}


int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &processes);


    printf("Enter the number of resources: ");
    scanf("%d", &resources);


    printf("Enter the available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }


    printf("Enter the maximum resource matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }


    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }


    calculateNeed();
    isSafeState();


    return 0;
}



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

//producer consumer using threads and semaphores 

import java.util.LinkedList;
import java.util.concurrent.Semaphore;


class ProducerConsumer {
  private final LinkedList<Integer> buffer = new LinkedList<>();
  private final int capacity = 5; // Size of the buffer
  private final Semaphore mutex; // Mutual exclusion for buffer access
  private final Semaphore empty; // Semaphore to count empty slots in buffer
  private final Semaphore full; // Semaphore to count full slots in buffer


  public ProducerConsumer() {
    mutex = new Semaphore(1); // Binary semaphore for mutual exclusion
    empty = new Semaphore(capacity); // Counting semaphore for empty slots
    full = new Semaphore(0); // Counting semaphore for full slots
  }


  // Producer class
  class Producer implements Runnable {
    @Override
    public void run() {
      int item = 0; // Item to be produced
      while (true) {
        try {
          empty.acquire(); // Wait if buffer is full
          mutex.acquire(); // Protect buffer access


          // Critical Section for Producer (Inserting item)
          buffer.add(item);
          System.out.println("Produced: " + item);
          item++; // Increment item to produce new one


          mutex.release(); // Release buffer access
          full.release(); // Signal that there's a full slot now


          // Simulate production time
          Thread.sleep(1000);
        } catch (InterruptedException e) {
          System.out.println(e.getMessage());
        }
      }
    }
  }


  // Consumer class
  class Consumer implements Runnable {
    @Override
    public void run() {
      while (true) {
        try {
          full.acquire(); // Wait if buffer is empty
          mutex.acquire(); // Protect buffer access


          // Critical Section for Consumer (Removing item)
          int item = buffer.removeFirst();
          System.out.println("Consumed: " + item);


          mutex.release(); // Release buffer access
          empty.release(); // Signal that there's an empty slot now


          // Simulate consumption time
          Thread.sleep(1500);
        } catch (InterruptedException e) {
          System.out.println(e.getMessage());
        }
      }
    }
  }


  public static void main(String[] args) {
    ProducerConsumer pc = new ProducerConsumer();


    // Creating producer and consumer threads
    Thread producer1 = new Thread(pc.new Producer());
    Thread producer2 = new Thread(pc.new Producer());
    Thread producer3 = new Thread(pc.new Producer());
    Thread consumer1 = new Thread(pc.new Consumer());
    Thread consumer2 = new Thread(pc.new Consumer());


    // Start threads
    producer1.start();
    producer2.start();
    producer3.start();
    consumer1.start();
    consumer2.start();
  }
}



