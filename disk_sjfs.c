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
