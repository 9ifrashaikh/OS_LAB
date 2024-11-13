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
