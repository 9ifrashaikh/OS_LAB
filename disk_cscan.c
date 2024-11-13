// disk C sacn 
#include <stdio.h>
#include <stdlib.h>


void CSCAN(int head, int requests[], int n, int disk_size) {
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


    printf("\nC-SCAN Disk Scheduling\n");
    printf("Initial Head Position: %d\n", head);


    printf("\nRequest\tCurrent Head Position\tSeek Time\n");
    printf("-------\t----------------------\t---------\n");


    // Move towards the end of the disk serving requests on the right
    for (i = pos; i < n; i++) {
        int seek_time = abs(requests[i] - head);
        total_seek_time += seek_time;
        printf("%d\t\t%d\t\t\t%d\n", requests[i], head, seek_time);
        head = requests[i];
    }


    // Jump to the beginning of the disk
    if (head != disk_size - 1) {
        int seek_time = abs((disk_size - 1) - head);
        total_seek_time += seek_time;
        printf("%d\t\t%d\t\t\t%d\n", disk_size - 1, head, seek_time);
        head = 0; // Jump to 0 (beginning of the disk)
        printf("%d\t\t%d\t\t\t%d\n", 0, disk_size - 1, head);
    }


    // Continue serving requests from the start to the head position
    for (i = 0; i < pos; i++) {
        int seek_time = abs(requests[i] - head);
        total_seek_time += seek_time;
        printf("%d\t\t%d\t\t\t%d\n", requests[i], head, seek_time);
        head = requests[i];
    }


    printf("\nTotal Seek Time: %d\n", total_seek_time);
}


int main() {
    int n, head, disk_size;


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


    // Call the CSCAN function to calculate seek time
    CSCAN(head, requests, n, disk_size);


    return 0;
}

// another one 
// C-SCAN 
#include <stdio.h>
#include <stdlib.h>

// Function to simulate C-SCAN Disk Scheduling
void CSCAN_Disk_Scheduling(int start, int requests[], int n, int max_track) {
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

    // Calculate total seek time by moving towards one direction (right), then wrapping around to 0 and moving to the right again
    int current_position = start;
    int seek_time = 0;

    // Print the table header
    printf("Track No. | Disk Head Position | Seek Time\n");
    printf("-------------------------------------------\n");

    // Move to the rightmost request and service requests
    for (int i = 0; i < right_count; i++) {
        seek_time = abs(current_position - right[i]);
        total_seek_time += seek_time;
        current_position = right[i];
        printf("%9d | %17d | %9d\n", right[i], current_position, seek_time);
    }

    // After reaching max track, jump to the beginning (track 0) and move to the leftmost request
    seek_time = abs(current_position - max_track);
    total_seek_time += seek_time;
    current_position = max_track;
    printf("%9d | %17d | %9d\n", max_track, current_position, seek_time);

    // Service the left requests after wrapping around
    for (int i = 0; i < left_count; i++) {
        seek_time = abs(current_position - left[i]);
        total_seek_time += seek_time;
        current_position = left[i];
        printf("%9d | %17d | %9d\n", left[i], current_position, seek_time);
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

    // Call C-SCAN Disk Scheduling function to calculate and print results
    CSCAN_Disk_Scheduling(start, requests, n, max_track);

    return 0;
}
