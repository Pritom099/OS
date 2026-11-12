#include <stdio.h>
int process[1000], burst_time[1000];
int gantt_chart[1000];
int i, n;
double average_waiting = 0, average_turnAround = 0;

void calculate_ganttChart()
{
    gantt_chart[0] = 0;
    for (i = 1; i <= n; i++)
    {
        gantt_chart[i] = gantt_chart[i - 1] + burst_time[i];
    }
    printf("\nGantt Chart:\n");
    for (i = 1; i <= n; i++)
    {
        printf("P%d", process[i]);
        if (i < n)
            printf(" -> ");
    }
    printf("\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d", gantt_chart[i]);

        if (i < n)
            printf("     ");
    }

    printf("\n");
}

void find_Waiting_Time()
{
    for (i = 0; i < n; i++)
    {
        average_waiting += gantt_chart[i];
    }
}

void find_TurnAround_Time()
{
    for (i = 1; i <= n; i++)
    {
        average_turnAround += gantt_chart[i];
    }
}

int main()
{
    printf("Enter number of processes = ");
    scanf("%d", &n);

    printf("Process - Burst Time:\n");

    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &process[i], &burst_time[i]);
    }

    calculate_ganttChart();

    find_Waiting_Time();
    find_TurnAround_Time();

    printf("\nAverage Waiting Time: %.2lf\n",
           average_waiting / n);

    printf("Average Turnaround Time: %.2lf\n",
           average_turnAround / n);

    return 0;
}
