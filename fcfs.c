#include <stdio.h>

int main() {
    int n, at[10], bt[10], wt[10], tat[10], ct[10], sum = 0, i, j, k;
    float totaltat = 0, totalwt = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("\nEnter The Process Arrival Time & Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("Enter Arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    /* Calculate completion time of processes */
    sum = at[0];
    for (j = 0; j < n; j++) {
        sum += bt[j];
        ct[j] = sum;
    }

    /* Calculate Turn Around time */
    for (k = 0; k < n; k++) {
        tat[k] = ct[k] - at[k];
        totaltat += tat[k];
    }

    /* Calculate Waiting time */
    for (k = 0; k < n; k++) {
        wt[k] = tat[k] - bt[k];
        totalwt += wt[k];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\t\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", totaltat / n);
    printf("Average Waiting Time: %.2f\n", totalwt / n);

    return 0;
}