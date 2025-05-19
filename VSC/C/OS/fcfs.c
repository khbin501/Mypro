//fcfs
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int finish_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
} Process;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s inputfile outputfile\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    if (!in || !out) {
        perror("File error");
        return 1;
    }

    Process k[MAX];
    int n = 0;
    while (fscanf(in, "%d %*d %d %d", &k[n].pid, &k[n].arrival_time, &k[n].burst_time) == 3) {
        n++;
    }

    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (k[j].arrival_time > k[j + 1].arrival_time) {
            Process temp = k[j];
            k[j] = k[j + 1];
            k[j + 1] = temp;
        }
    }
}

    int time = 0;
    float total_wait = 0, total_response = 0, total_turnaround = 0;
    fprintf(out, "Scheduling: FCFS\n==========================================\n");

    for (int i = 0; i < n; i++) {
        if (time < k[i].arrival_time) {
            while (time < k[i].arrival_time) {
                fprintf(out, "<time %d> ---- system is idle ----\n", time++);
            }
        }
        k[i].start_time = time;
        k[i].finish_time = time + k[i].burst_time;
        k[i].waiting_time = time - k[i].arrival_time;
        k[i].response_time = k[i].start_time - k[i].arrival_time;
        k[i].turnaround_time = k[i].finish_time - k[i].arrival_time;

        for (int t = 0; t < k[i].burst_time; t++) {
            fprintf(out, "<time %d> process %d is running\n", time, k[i].pid);
            time++;
        }
        fprintf(out, "<time %d> process %d is finished\n------------------------------- (Context-Switch)\n", time, k[i].pid);

        total_wait += k[i].waiting_time;
        total_response += k[i].response_time;
        total_turnaround += k[i].turnaround_time;
    }

    fprintf(out, "<time %d> all processes finish\n", time);
    fprintf(out, "==========================================\n");
    fprintf(out, "Average CPU usage: 100.00 %%\n");
    fprintf(out, "Average waiting time: %.2f\n", total_wait / n);
    fprintf(out, "Average response time: %.2f\n", total_response / n);
    fprintf(out, "Average turnaround time: %.2f\n", total_turnaround / n);

    fclose(in);
    fclose(out);
    return 0;
}
