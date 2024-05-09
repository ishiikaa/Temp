#include <stdio.h>
#include <math.h>

#define MAX_SIZE 20

void FCFS(int arr[], int size, int head) {
    int seek_count = 0;
    int cur_track, distance;
    int seek_sequence[MAX_SIZE];

    for (int i = 0; i < size; i++) {
        cur_track = arr[i];

        // Calculate absolute distance
        distance = abs(head - cur_track);

        // Increase the total seek count
        seek_count += distance;

        // Store the current track in the seek sequence array
        seek_sequence[i] = cur_track;

        // Accessed track is now the new head
        head = cur_track;
    }

    // Print total number of seek operations
    printf("Total number of seek operations: %d\n", seek_count);

    // Print seek sequence
    printf("Seek Sequence is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", seek_sequence[i]);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;
    int head;

    // Input number of disk requests
    printf("Enter the number of disk requests (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid number of disk requests\n");
        return 1; // Exit with error
    }

    // Input disk requests
    printf("Enter the disk requests:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input initial position of the disk head
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    // Call FCFS function with user inputs
    FCFS(arr, size, head);

    return 0;
}
