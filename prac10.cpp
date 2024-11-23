#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Process {
    int id, arrival_time, burst_time, remaining_time, completion_time, waiting_time, turnaround_time;
};

bool compareArrivalTime(Process p1, Process p2) {
    return p1.arrival_time < p2.arrival_time;
}

int main() {
    int n;
    std::cout << "Enter number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        std::cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;  // Initialize remaining time
    }

    // Sort processes based on arrival time
    std::sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0, completed = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    std::vector<bool> isCompleted(n, false);

    // Execute processes until all are completed
    while (completed < n) {
        int shortestProcess = -1;
        int minRemainingTime = INT_MAX;

        // Find the process with the shortest remaining time that has arrived
        for (int i = 0; i < n; ++i) {
            if (!isCompleted[i] && processes[i].arrival_time <= currentTime && processes[i].remaining_time < minRemainingTime) {
                minRemainingTime = processes[i].remaining_time;
                shortestProcess = i;
            }
        }

        if (shortestProcess != -1) {
            // Process the shortest job
            processes[shortestProcess].remaining_time--;
            currentTime++;

            // If the process is completed
            if (processes[shortestProcess].remaining_time == 0) {
                processes[shortestProcess].completion_time = currentTime;
                processes[shortestProcess].turnaround_time = processes[shortestProcess].completion_time - processes[shortestProcess].arrival_time;
                processes[shortestProcess].waiting_time = processes[shortestProcess].turnaround_time - processes[shortestProcess].burst_time;

                totalWaitingTime += processes[shortestProcess].waiting_time;
                totalTurnaroundTime += processes[shortestProcess].turnaround_time;

                isCompleted[shortestProcess] = true;
                completed++;
            }
        } else {
            // If no process is ready to execute, increment time
            currentTime++;
        }
    }

    // Output the results
    std::cout << "\nProcess execution details (SRTF Scheduling):\n";
    for (const auto& p : processes) {
        std::cout << "P" << p.id << " (Arrival Time: " << p.arrival_time
                  << ", Burst Time: " << p.burst_time
                  << ", Completion Time: " << p.completion_time
                  << ", Turnaround Time: " << p.turnaround_time
                  << ", Waiting Time: " << p.waiting_time << ")\n";
    }

    std::cout << "\nAverage Waiting Time: " << totalWaitingTime / n << std::endl;
    std::cout << "Average Turnaround Time: " << totalTurnaroundTime / n << std::endl;

    return 0;
}
