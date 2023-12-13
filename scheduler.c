//C Program for Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* completion_times;
int* waiting_times;
int* turnaround_times;
int* process_done;
int findMinIndex(int arr[], int n){
 int minInd = -1;
 for (int i = 0; i < n; i++) {
 if (process_done[i] == 1) {
 continue;
 }
 if (minInd == -1 || arr[i] < arr[minInd]) {
 minInd = i;
 }
 }
 return minInd;
}
void fcfs(int arrival_times[], int burst_times[], int n) {
 completion_times = (int*)malloc(n * sizeof(int));
 turnaround_times = (int*)malloc(n * sizeof(int));
 waiting_times = (int*)malloc(n * sizeof(int));
 process_done = (int*)malloc(n * sizeof(int));
 for (int i = 0; i < n; i++){
 completion_times[i] = 0;
 turnaround_times[i] = 0;
 waiting_times[i] = 0;
 process_done[i] = 0;
 }
 int i = 0, process_count = 0, ct = 0;
 while(process_count != n){
 if(i == n && process_count != n){
 i = 0;
 }
 int min = findMinIndex(arrival_times, n);
 if(i == min){
 ct += burst_times[i];
 completion_times[i] = ct;
 turnaround_times[i] = completion_times[i] - arrival_times[i];
 waiting_times[i] = turnaround_times[i] - burst_times[i];
 process_done[i] = 1;
 process_count++;
 }
 i++;
 }
}
void sjf(int arrival_times[], int burst_times[], int n) {
 completion_times = (int*)malloc(n * sizeof(int));
 turnaround_times = (int*)malloc(n * sizeof(int));
 waiting_times = (int*)malloc(n * sizeof(int));
 process_done = (int *)malloc(n * sizeof(int));
 int remaining_time[n], count = 0, ct = 0, sum = 0;
 for (int i = 0; i < n; i++) {
 completion_times[i] = 0;
 waiting_times[i] = 0;
 turnaround_times[i] = 0;
 remaining_time[i] = burst_times[i];
 sum += burst_times[i];
 }
 int index, index1, index2;
 while(count != n){
 index1 = findMinIndex(arrival_times, n);
 index2 = findMinIndex(remaining_time, n);
 if(index1 == index2 || arrival_times[index2] !=
arrival_times[index1]){
 index = index1;
 } else{
 index = index2;
 }
 process_done[index] = 1;
 remaining_time[index] -= burst_times[index];
 ct += burst_times[index];
 completion_times[index] = ct;
 turnaround_times[index] = completion_times[index] -
arrival_times[index];
 waiting_times[index] = turnaround_times[index] - burst_times[index];
 count++;
 }
}
void priority_scheduling(int arrival_times[], int burst_times[], int
priorities[], int n) {
 completion_times = (int*)malloc(n * sizeof(int));
 turnaround_times = (int*)malloc(n * sizeof(int));
 waiting_times = (int*)malloc(n * sizeof(int));
 process_done = (int *)malloc(n * sizeof(int));
 int count = 0, ct = 0, sum = 0;
 for (int i = 0; i < n; i++) {
 completion_times[i] = 0;
 waiting_times[i] = 0;
 turnaround_times[i] = 0;
 }
 int index, index1, index2;
 while(count != n) {
 index1 = findMinIndex(arrival_times, n);
 index2 = findMinIndex(priorities, n);
 if(index1 == index2 || arrival_times[index2] !=
arrival_times[index1]){
 index = index1;
 } else{
 index = index2;
 }
 process_done[index] = 1;
 ct += burst_times[index];
 completion_times[index] = ct;
 turnaround_times[index] = completion_times[index] -
arrival_times[index];
 waiting_times[index] = turnaround_times[index] - burst_times[index];
 count++;
 }
}
void round_robin_scheduling(int arrival_times[], int burst_times[], int
time_quantum, int n) {
 completion_times = (int*)malloc(n * sizeof(int));
 turnaround_times = (int*)malloc(n * sizeof(int));
 waiting_times = (int*)malloc(n * sizeof(int));
 for (int i = 0; i < n; i++) {
 completion_times[i] = 0;
 waiting_times[i] = 0;
 turnaround_times[i] = 0;
 }
 int remaining_burst_times[n];
 for (int i = 0; i < n; i++) {
 remaining_burst_times[i] = burst_times[i];
 }
 int time = 0;
 int flag = 0;
 while (1) {
 flag = 0;
 for (int i = 0; i < n; i++) {
 if (remaining_burst_times[i] > 0) {
 flag = 1;
 if (remaining_burst_times[i] > time_quantum) {
 time += time_quantum;
 remaining_burst_times[i] -= time_quantum;
 } else {
 time += remaining_burst_times[i];
 waiting_times[i] = time - arrival_times[i] -
burst_times[i];
 remaining_burst_times[i] = 0;
 completion_times[i] = time;
 }
 }
 }
 if (flag == 0) {
 break;
 }
 }
 for (int i = 0; i < n; i++) {
 turnaround_times[i] = completion_times[i] - arrival_times[i];
 }
}
int main(int argc, char* argv[]) {
 if (argc < 5) {
 // printf("%d %d\n", argc, argv[0]);
 fprintf(stderr, "Usage: %s <algorithm> <n> <time_quantum>
<process_data...>\n", argv[0]);
 return EXIT_FAILURE;
 }

 char *algorithm = argv[1];
 int n = atoi(argv[2]);
 int time_quantum = atoi(argv[3]);
 int* arrival_times = malloc(n * sizeof(int));
 int* burst_times = malloc(n * sizeof(int));
 int* priorities = malloc(n * sizeof(int));
 for (int i = 0; i < n; i++) {
 arrival_times[i] = atoi(argv[4 + 3 * i]);
 burst_times[i] = atoi(argv[5 + 3 * i]);
 priorities[i] = atoi(argv[6 + 3 * i]);
 }
 if (strcmp(algorithm, "fcfs") == 0) {
 fcfs(arrival_times, burst_times, n);
 } else if (strcmp(algorithm, "sjf") == 0) {
 sjf(arrival_times, burst_times, n);
 } else if (strcmp(algorithm, "priority") == 0) {
 priority_scheduling(arrival_times, burst_times, priorities, n);
 } else if (strcmp(algorithm, "round_robin") == 0) {
 round_robin_scheduling(arrival_times, burst_times, time_quantum, n);
 } else {
 printf("Invalid algorithm\n");
 return 1;
 }
 for (int i = 0; i < n; i++) {
 printf("%d %d %d %d %d %d %d\n", i + 1, arrival_times[i], burst_times[i],
priorities[i], completion_times[i], turnaround_times[i], waiting_times[i]);
 }
 free(arrival_times);
 free(burst_times);
 free(priorities);
 free(completion_times);
 free(turnaround_times);
 free(waiting_times);
 free(process_done);
 return 0;
}
