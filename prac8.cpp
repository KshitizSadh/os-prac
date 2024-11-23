#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id, burst_time, waiting_time, turnaround_time;
};

bool compare(Process p1, Process p2) {
    return p1.burst_time < p2.burst_time;
}

int main() {
    int n;
    std::cout << "Enter number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter burst time for process " << i + 1 << ": ";
        std::cin >> processes[i].burst_time;
        processes[i].id = i + 1;
    }

    std::sort(processes.begin(), processes.end(), compare);

    int time = 0;
    double total_wt = 0, total_tat = 0;
    std::cout << "Process Execution Order (SJF):\n";
    for (auto& p : processes) {
        p.waiting_time = time;
        p.turnaround_time = p.waiting_time + p.burst_time;
        time += p.burst_time;

        total_wt += p.waiting_time;
        total_tat += p.turnaround_time;

        std::cout << "P" << p.id << " (Burst: " << p.burst_time
                  << ", Waiting Time: " << p.waiting_time
                  << ", Turnaround Time: " << p.turnaround_time << ")\n";
    }

    std::cout << "Average Waiting Time: " << total_wt / n << std::endl;
    std::cout << "Average Turnaround Time: " << total_tat / n << std::endl;

    return 0;
}
