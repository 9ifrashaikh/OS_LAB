// disk first come first serve 
//first come first serve scheduling algo 

#include <stdio.h>
#include <stdlib.h>

// Function to calculate total seek time and print the request sequence
void FCFS_Disk_Scheduling(int start, int requests[], int n) {
    int total_seek_time = 0;  // Initialize total seek time
    int prev = start;         // Set previous position as the start position
    
    // Print the table header
    printf("Track No. | Disk Head Position | Seek Time\n");
    printf("-------------------------------------------\n");
    
    // Process each request in order (FCFS)
    for (int i = 0; i < n; i++) {
        int seek_time = abs(requests[i] - prev);  // Calculate seek time
        total_seek_time += seek_time;             // Accumulate seek time
        prev = requests[i];                       // Update previous position
        
        // Print the current request and its seek time
        printf("%9d | %17d | %9d\n", requests[i], prev, seek_time);
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
    
    // Call FCFS Disk Scheduling function to calculate and print results
    FCFS_Disk_Scheduling(start, requests, n);
    
    return 0;
}
