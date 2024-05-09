#include <stdio.h>

void implementBestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[processes]; // Array to store the block id of the allocated block to a process
    int occupied[blocks]; // Array to store the status of each block (occupied or not)
    
    // Initialize allocation array to -1, meaning nothing is allocated initially
    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }
    
    // Initialize occupied array to 0, meaning no block is occupied initially
    for (int i = 0; i < blocks; i++) {
        occupied[i] = 0;
    }
 
    // Pick each process and find suitable blocks according to its size and assign to it
    for (int i = 0; i < processes; i++) {
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++) {
            // Check if the block can accommodate the process and is not occupied
            if (blockSize[j] >= processSize[i] && !occupied[j]) {
                // If it's the first suitable block found, assign it
                if (indexPlaced == -1)
                    indexPlaced = j;
                // If a smaller block is found later, assign it instead
                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }
 
        // If a suitable block is found for the process
        if (indexPlaced != -1) {
            // Allocate this block to the process
            allocation[i] = indexPlaced;
            // Mark the block as occupied
            occupied[indexPlaced] = 1;
        }
    }
 
    // Print allocation status of each process
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++) {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1); // Print the block number allocated to the process
        else
            printf("Not Allocated\n"); // If not allocated, print "Not Allocated"
    }
}

// Driver code
int main() {
    int blockSize[] = {100, 50, 30, 120, 35}; // Memory block sizes
    int processSize[] = {40, 10, 30, 60}; // Process sizes
    int blocks = sizeof(blockSize) / sizeof(blockSize[0]); // Number of memory blocks
    int processes = sizeof(processSize) / sizeof(processSize[0]); // Number of processes

    implementBestFit(blockSize, blocks, processSize, processes); // Call the implementBestFit function

    return 0;
}
