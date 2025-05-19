#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int finish_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
    bool finished;
} Process;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s inputfile outputfile time_quantum\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    int time_quantum = atoi(argv[3]);

    if (!in || !out) {
        perror("File error");
        return 1;
    }

    Process p[MAX];
    int n = 0;

    while (fscanf(in, "%d %*d %d %d", &p[n].pid, &p[n].arrival_time, &p[n].burst_time) == 3) {
        p[n].remaining_time = p[n].burst_time;
        p[n].start_time = -1;
        p[n].finished = false;
        n++;
    }

    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (p[j].arrival_time > p[j + 1].arrival_time) {
            Process temp = p[j];
            p[j] = p[j + 1];
            p[j + 1] = temp;
        }
    }
}

    int time = 0;
    int completed = 0;
    int index = 0;
    float total_wait = 0, total_response = 0, total_turnaround = 0;

    fprintf(out, "Scheduling: Round Robin\n==========================================\n");

    while (completed < n) {
        int executed = 0;

        for (int i = 0; i < n; i++) {
            int id = (index + i) % n;
            if (p[id].arrival_time <= time && p[id].remaining_time > 0) {
                if (p[id].start_time == -1) {
                    p[id].start_time = time;
                    p[id].response_time = time - p[id].arrival_time;
                }

                int run_time = (p[id].remaining_time >= time_quantum) ? time_quantum : p[id].remaining_time;

                for (int t = 0; t < run_time; t++) {
                    fprintf(out, "<time %d> process %d is running\n", time, p[id].pid);
                    time++;
                }

                p[id].remaining_time -= run_time;

                if (p[id].remaining_time == 0) {
                    p[id].finish_time = time;
                    p[id].turnaround_time = time - p[id].arrival_time;
                    p[id].waiting_time = p[id].turnaround_time - p[id].burst_time;
                    p[id].finished = true;
                    completed++;
                    fprintf(out, "<time %d> process %d is finished\n", time, p[id].pid);
                    fprintf(out, "------------------------------- (Context-Switch)\n");

                    total_wait += p[id].waiting_time;
                    total_response += p[id].response_time;
                    total_turnaround += p[id].turnaround_time;
                } else {
                    fprintf(out, "------------------------------- (Context-Switch)\n");
                }

                index = (id + 1) % n;
                executed = 1;
                break;
            }
        }

        if (!executed) {
            fprintf(out, "<time %d> ---- system is idle ----\n", time);
            time++;
        }
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
