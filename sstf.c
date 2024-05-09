#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the index of the nearest request to the head position
int findNearestRequest(int *requestSequence, int head, int *visited, int n) {
    int minDistance = INT_MAX;
    int nearestIndex = -1;

    // Find the nearest unvisited request
    for (int i = 0; i < n; i++) {
        if (!visited[i] && abs(requestSequence[i] - head) < minDistance) {
            minDistance = abs(requestSequence[i] - head);
            nearestIndex = i;
        }
    }

    return nearestIndex;
}

// Function to calculate total seek time using SSTF algorithm
int calculateSeekTime(int *requestSequence, int head, int n) {
    int seekTime = 0;
    int visited[n];

    // Initialize all requests as unvisited
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Process requests
    for (int i = 0; i < n; i++) {
        int nearestIndex = findNearestRequest(requestSequence, head, visited, n);

        // Mark the nearest request as visited
        visited[nearestIndex] = 1;

        // Update seek time and head position
        seekTime += abs(requestSequence[nearestIndex] - head);
        head = requestSequence[nearestIndex];
    }

    return seekTime;
}

int main() {
    int n, head;

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

    // Calculate and print total seek time
    int seekTime = calculateSeekTime(requestSequence, head, n);
    printf("Total seek time using SSTF: %d\n", seekTime);

    free(requestSequence);
    return 0;
}
