#include <stdio.h>

struct Process
{
    int pid, arrival_time, burst_time;
};

int find_turnaround(struct Process *processes, int len, int *waiting_time);

int find(struct Process *processes, int len){
    int total = 0;
    for (int i = 0; i < len; i++)
    {
        total += processes[i].burst_time;
    }
    return total;
}

int find_turnaround(struct Process *processes, int len, int *waiting_time){
    int total = 0;
    printf("Turnaround Time For Each Process : ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", waiting_time[i] + processes[i].burst_time);
        total += waiting_time[i] + processes[i].burst_time;
    }
    printf("Average Turnaround Time : %d", total / len);
}

int find_avg_waiting(struct Process *processes, int len)
{
    int curr_waiting = 0;
    int waiting_time[len];

    waiting_time[0] = 0;

    for (int i = 1; i < len; i++)
    {
        curr_waiting = find(processes, i);
        waiting_time[i] = curr_waiting - processes[i].arrival_time;
    }

    int total = 0;
    printf("Average Waiting Time For Each Process : ");
    for(int i = 0; i < len; i++)
    {
        printf("%d ", waiting_time[i]);
        total+=waiting_time[i];
    }
    printf("Average waiting time : %d" , total/len);

    find_turnaround(processes,len,waiting_time);
}

int main()
{
    struct Process p1, p2, p3;
    p1 = (struct Process){1, 0, 3};
    p2 = (struct Process){2, 2, 6};
    p3 = (struct Process){3, 4, 5};

    struct Process processes[] = {p1, p2, p3};
    int len = sizeof(processes) / sizeof(processes[0]);
    find_avg_waiting(processes, len);

    return 0;
}