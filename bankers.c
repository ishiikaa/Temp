#include <stdio.h>

int main() {
    // Number of tasks and resource types
    int n = 5; // Number of tasks
    int m = 3; // Number of resource types

    // Allocation matrix: how many resources each task currently has
    int alloc[5][3] = { { 0, 1, 0 },   // Task A
                        { 2, 0, 0 },   // Task B
                        { 3, 0, 2 },   // Task C
                        { 2, 1, 1 },   // Task D
                        { 0, 0, 2 } }; // Task E

    // Maximum demand matrix: maximum number of resources each task might need
    int max[5][3] = { { 7, 5, 3 },   // Task A
                      { 3, 2, 2 },   // Task B
                      { 9, 0, 2 },   // Task C
                      { 2, 2, 2 },   // Task D
                      { 4, 3, 3 } }; // Task E

    // Available resources
    int avail[3] = { 3, 3, 2 }; // Printers, scanners, projectors

    // Helper arrays and variables
    int f[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++) {
        f[k] = 0; // Initialize all tasks as unprocessed
    }

    // Calculate the need matrix: remaining need of resource for each task
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    // Checking if tasks can be executed safely
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) { // If the task hasn't been processed yet
                int flag = 0; // Flag indicating if the task can be executed
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) { // If the task needs more resources than available
                        flag = 1; // Set the flag to indicate the task can't be executed
                        break;
                    }
                }
                if (flag == 0) { // If the task can be executed safely
                    ans[ind++] = i; // Add the task to the list of tasks that can be executed
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y]; // Update available resources
                    f[i] = 1; // Mark the task as processed
                }
            }
        }
    }

    // Checking if all tasks have been processed
    int flag = 1;
    for(int i = 0; i < n; i++) {
        if(f[i] == 0) {
            flag = 0; // Set the flag to indicate that not all tasks have been processed
            printf("The following system is not safe"); // Output indicating the system is not safe
            break;
        }
    }
    
    // If all tasks have been processed, print the safe sequence
    if(flag == 1) {
        printf("Following is the SAFE Sequence\n");
        for (int i = 0; i < n - 1; i++)
            printf(" Task %c ->", ans[i] + 'A'); // Convert task index to task name (A, B, C...)
        printf(" Task %c", ans[n - 1] + 'A');
    }

    return 0;
}
