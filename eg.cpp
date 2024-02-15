#include <stdio.h>

struct Process {
    char name;
    int arrivalTime, burstTime, waitingTime, turnaroundTime, remainingTime, completionTime;
} queue1[10], queue2[10], queue3[10];

int numProcesses;

void sortByArrivalTime() {
    struct Process temp;
    int i, j;
    for (i = 0; i < numProcesses; i++) {
        for (j = i + 1; j < numProcesses; j++) {
            if (queue1[i].arrivalTime > queue1[j].arrivalTime) {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }
}

int main() {
    int i, j, k = 0, r = 0, time = 0, timeQuantum1 = 5, timeQuantum2 = 8, flag = 0;
    char processName;
    
    printf("Enter number of processes:");
    scanf("%d", &numProcesses);
    
    for (i = 0, processName = 'A'; i < numProcesses; i++, processName++) {
        queue1[i].name = processName;
        printf("\nEnter the arrival time and burst time of process %c: ", queue1[i].name);
        scanf("%d%d", &queue1[i].arrivalTime, &queue1[i].burstTime);
        queue1[i].remainingTime = queue1[i].burstTime;
    }
    
    sortByArrivalTime();
    time = queue1[0].arrivalTime;
    printf("Processes in first queue following RR with time quantum=5\n");
    printf("Process\t\tBurstTime\t\tWaitingTime\t\tTurnaroundTime\t\t\n");
    
    for (i = 0; i < numProcesses; i++) {
        if (queue1[i].remainingTime <= timeQuantum1) {
            time += queue1[i].remainingTime;
            queue1[i].remainingTime = 0;
            queue1[i].waitingTime = time - queue1[i].arrivalTime - queue1[i].burstTime;
            queue1[i].turnaroundTime = time - queue1[i].arrivalTime;
            printf("%c\t\t%d\t\t\t%d\t\t\t%d\n", queue1[i].name, queue1[i].burstTime, queue1[i].waitingTime, queue1[i].turnaroundTime);
        } else {
            queue2[k].waitingTime = time;
            time += timeQuantum1;
            queue1[i].remainingTime -= timeQuantum1;
            queue2[k].burstTime = queue1[i].remainingTime;
            queue2[k].remainingTime = queue2[k].burstTime;
            queue2[k].name = queue1[i].name;
            k = k + 1;
            flag = 1;
        }
    }
    
    if (flag == 1) {
        printf("Processes in second queue following RR with time quantum=8\n");
        printf("Process\t\tBurstTime\t\tWaitingTime\t\tTurnaroundTime\t\t\n");
    }
    
    for (i = 0; i < k; i++) {
        if (queue2[i].remainingTime <= timeQuantum2) {
            time += queue2[i].remainingTime;
            queue2[i].remainingTime = 0;
            queue2[i].waitingTime = time - timeQuantum1 - queue2[i].burstTime;
            queue2[i].turnaroundTime = time - queue2[i].arrivalTime;
            printf("%c\t\t%d\t\t\t%d\t\t\t%d\n", queue2[i].name, queue2[i].burstTime, queue2[i].waitingTime, queue2[i].turnaroundTime);
        } else {
            queue3[r].arrivalTime = time;
            time += timeQuantum2;
            queue2[i].remainingTime -= timeQuantum2;
            queue3[r].burstTime = queue2[i].remainingTime;
            queue3[r].remainingTime = queue3[r].burstTime;
            queue3[r].name = queue2[i].name;
            r = r + 1;
            flag = 2;
        }
    }
    
    if (flag == 2) {
        printf("Processes in third queue following FCFS\n");
    }
    
    for (i = 0; i < r; i++) {
        if (i == 0)
            queue3[i].completionTime = queue3[i].burstTime + time - timeQuantum1 - timeQuantum2;
        else
            queue3[i].completionTime = queue3[i - 1].completionTime + queue3[i].burstTime;
    }
    
    for (i = 0; i < r; i++) {
        queue3[i].turnaroundTime = queue3[i].completionTime;
        queue3[i].waitingTime = queue3[i].turnaroundTime - queue3[i].burstTime;
        printf("%c\t\t%d\t\t\t%d\t\t\t%d\n", queue3[i].name, queue3[i].burstTime, queue3[i].waitingTime, queue3[i].turnaroundTime);
    }
    
    return 0;
}
