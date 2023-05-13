#include <stdio.h>
#include <stdbool.h>
typedef struct
{
    int pid, at, ct, bt, st, wt, tat, start, fin;
} Process;
int main()
{
    Process proc[10], temp;
    float total_tat = 0, total_wt = 0;
    int n;
    printf("Enter number of processes : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d : \n", i + 1);
        scanf("%d", &proc[i].at);

        printf("Enter burst time for process %d : \n", i + 1);
        scanf("%d", &proc[i].bt);
        proc[i].pid = i + 1;
        printf("\n");
    }

    int complete = 0, t = 0, shortest;

    bool check = false;
    for (int i = 0; i < n; i++)
    {
        proc[i].fin = 0;
    }

    while (complete != n)
    {
        int min = 1000;
        for (int j = 0; j < n; j++)
        {
            if ((proc[j].bt < min) && (proc[j].at <= t) && (proc[j].fin == 0))
            {
                min = proc[j].bt;
                shortest = j;
                check = true;
            }
        }
        if (check == false)
        {
            t++;
            continue;
        }
        proc[shortest].start = t;
        t = t + proc[shortest].bt;
        proc[shortest].ct = t;
        proc[shortest].fin = 1;

        complete++;
        check = false;
    }

    for (int i = 0; i < n; i++)
    {
        proc[i].tat = proc[i].ct - proc[i].at;
        proc[i].wt = proc[i].tat - proc[i].bt;
        total_tat = total_tat + proc[i].tat;
        total_wt = total_wt + proc[i].wt;
    }
    printf("PID\t\tARR_T\t\tBR_T\t\tCOMP_T\t\tTURN_T\t\tWAIT_T\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].ct, proc[i].tat, proc[i].wt);
    }

    printf("Average Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    printf("---GANTT CHART---\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d-----P%d-----%d\n", proc[i].st, proc[i].pid, proc[i].ct);
    }
    return 0;
}
