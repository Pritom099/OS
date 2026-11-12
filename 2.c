
#include <stdio.h>

int process[1000], burst_time[1000];
int gantt_chart[1000];
int arrival_time[1000];

int i, n, j;
double average_waiting = 0, average_turnAround = 0;

void selection_sort()
{
    for (i = 1; i < n; i++)
    {
        int position = i;

        for (j = i + 1; j <= n; j++)
        {
            if (arrival_time[j] < arrival_time[position])
                position = j;
        }

        // Swap arrival time
        int a = arrival_time[i];
        int b = arrival_time[position];

        arrival_time[i] = b;
        arrival_time[position] = a;

        // Swap process
        int x = process[i];
        int y = process[position];

        process[i] = y;
        process[position] = x;

        // Swap burst time
        int c = burst_time[i];
        int d = burst_time[position];

        burst_time[i] = d;
        burst_time[position] = c;
    }
}

void calculate_ganttChart()
{
    gantt_chart[0] = 0;

    for (i = 1; i <= n; i++)
    {
        if (gantt_chart[i - 1] < arrival_time[i])
            gantt_chart[i] = arrival_time[i] + burst_time[i];
        else
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
}

void find_Waiting_Time()
{
    for (i = 1; i <= n; i++)
    {
        average_waiting +=
            (gantt_chart[i - 1] > arrival_time[i]
                 ? gantt_chart[i - 1] - arrival_time[i]
                 : 0);
    }
}

void find_TurnAround_Time()
{
    for (i = 1; i <= n; i++)
    {
        average_turnAround +=
            (gantt_chart[i] - arrival_time[i]);
    }
}

int main()
{
    printf("Enter number of processes = ");
    scanf("%d", &n);

    printf("Process Burst_time Arrival_time:\n");

    for (i = 1; i <= n; i++)
    {
        scanf("%d %d %d",
              &process[i],
              &burst_time[i],
              &arrival_time[i]);
    }

    selection_sort();

    calculate_ganttChart();

    find_Waiting_Time();
    find_TurnAround_Time();

    printf("\n\nAverage Waiting Time: %.2lf\n",
           average_waiting / n);

    printf("Average Turnaround Time: %.2lf\n",
           average_turnAround / n);

    return 0;
}
