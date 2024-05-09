#include <stdio.h>
#include <stdlib.h>

// Function to calculate total seek time using LOOK algorithm
int calculateSeekTime(int *requestSequence, int head, int n, int direction) {
    int seekTime = 0;
    int currentIndex = 0;

    // Sort the request sequence in ascending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (requestSequence[i] > requestSequence[j]) {
                int temp = requestSequence[i];
                requestSequence[i] = requestSequence[j];
                requestSequence[j] = temp;
            }
        }
    }

    // Find the index of the current head position in the sorted sequence
    for (int i = 0; i < n; i++) {
        if (requestSequence[i] == head) {
            currentIndex = i;
            break;
        }
    }

    // If direction is 1, move towards higher cylinder numbers
    if (direction == 1) {
        for (int i = currentIndex; i < n; i++) {
            seekTime += abs(requestSequence[i] - head);
            head = requestSequence[i];
        }
        for (int i = currentIndex - 1; i >= 0; i--) {
            seekTime += abs(requestSequence[i] - head);
            head = requestSequence[i];
        }
    } 
    // If direction is -1, move towards lower cylinder numbers
    else if (direction == -1) {
        for (int i = currentIndex; i >= 0; i--) {
            seekTime += abs(requestSequence[i] - head);
            head = requestSequence[i];
        }
        for (int i = currentIndex + 1; i < n; i++) {
            seekTime += abs(requestSequence[i] - head);
            head = requestSequence[i];
        }
    }

    return seekTime;
}

int main() {
    int n, head, direction;

    // Input number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *requestSequence = (int *)malloc(n * sizeof(int));

    // Input the request sequence
    printf("Enter the disk request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requestSequence[i]);
    }

    // Input initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Input direction (1 for towards higher cylinder numbers, -1 for towards lower cylinder numbers)
    printf("Enter the direction (1 for towards higher cylinder numbers, -1 for towards lower cylinder numbers): ");
    scanf("%d", &direction);

    // Calculate and print total seek time
    int seekTime = calculateSeekTime(requestSequence, head, n, direction);
    printf("Total seek time using LOOK: %d\n", seekTime);

    free(requestSequence);
    return 0;
}
