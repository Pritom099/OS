
#include <stdio.h>
int i, j, n, m, e, sum = 0;

int process[1000];
int burst_time[1000];
int gantt_chart[1000];

/*
4
1 6
2 8
3 7
4 3
*/

void find_ganttChart()
{
    gantt_chart[0] = 0;
    gantt_chart[1] = burst_time[1];

    for (i = 2; i <= n; i++)
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
}

void find_avgWaiting_time()
{
    float awt = 0.0;
    sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += gantt_chart[i];
    }

    awt = (float)sum / n;

    printf("\nAverage Waiting Time = %.2f\n", awt);
}

void find_avgTurnAround_time()
{
    float att = 0.0;
    sum = 0;

    for (i = 1; i <= n; i++)
    {
        sum += gantt_chart[i];
    }

    att = (float)sum / n;

    printf("Average Turnaround Time = %.2f\n", att);
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

    // Selection Sort based on Burst Time
    for (i = 1; i < n; i++)
    {
        int position = i;

        for (j = i + 1; j <= n; j++)
        {
            if (burst_time[j] < burst_time[position])
                position = j;
        }

        // Swap Burst Time
        int a = burst_time[i];
        int b = burst_time[position];

        // Swap Process
        int x = process[i];
        int y = process[position];

        burst_time[i] = b;
        burst_time[position] = a;

        process[i] = y;
        process[position] = x;
    }

    find_ganttChart();

    find_avgWaiting_time();

    find_avgTurnAround_time();

    return 0;
}
