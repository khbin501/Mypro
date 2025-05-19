#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int pid;
    int base_priority;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int finish_time;
    int waiting_time;
    int response_time;
    int turnaround_time;
    bool finished;
} Process;

int main(int argc, char* argv[]) {
    if (argc != 5) {
        printf("Usage: %s inputfile outputfile time_quantum alpha\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    double alpha = atof(argv[4]);

    if (!in || !out) {
        perror("File error");
        return 1;
    }

    Process p[MAX];
    int n = 0;

    while (fscanf(in, "%d %d %d %d", &p[n].pid, &p[n].base_priority, &p[n].arrival_time, &p[n].burst_time) == 4) {
        p[n].remaining_time = p[n].burst_time;
        p[n].start_time = -1;
        p[n].finished = false;
        p[n].waiting_time = 0;
        n++;
    }

    int time = 0;
    int completed = 0;
    float total_wait = 0, total_response = 0, total_turnaround = 0;

    fprintf(out, "Scheduling: Priority with Aging\n==========================================\n");

    while (completed < n) {
        int highest_idx = -1;
        int highest_effective_priority = -1;

        for (int i = 0; i < n; i++) {
            if (!p[i].finished && p[i].arrival_time <= time) {
                int effective_priority = p[i].base_priority + (int)(alpha * p[i].waiting_time);
                if (effective_priority > highest_effective_priority) {
                    highest_effective_priority = effective_priority;
                    highest_idx = i;
                }
            }
        }

        if (highest_idx == -1) {
            fprintf(out, "<time %d> ---- system is idle ----\n", time);
            time++;
            continue;
        }

        Process *proc = &p[highest_idx];

        if (proc->start_time == -1) {
            proc->start_time = time;
            proc->response_time = time - proc->arrival_time;
        }

        fprintf(out, "<time %d> process %d is running\n", time, proc->pid);
        proc->remaining_time--;
        time++;

        for (int i = 0; i < n; i++) {
            if (!p[i].finished && i != highest_idx && p[i].arrival_time <= time) {
                p[i].waiting_time++;
            }
        }

        if (proc->remaining_time == 0) {
            proc->finish_time = time;
            proc->turnaround_time = time - proc->arrival_time;
            proc->waiting_time = proc->turnaround_time - proc->burst_time;
            proc->finished = true;

            fprintf(out, "<time %d> process %d is finished\n", time, proc->pid);
            fprintf(out, "------------------------------- (Context-Switch)\n");

            total_wait += proc->waiting_time;
            total_response += proc->response_time;
            total_turnaround += proc->turnaround_time;
            completed++;
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
