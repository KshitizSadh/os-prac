#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

struct Process {
    int id, arrival_time, burst_time;
};

// Comparison function to sort processes by arrival time
bool compareByArrival(const Process& a, const Process& b) {
    return a.arrival_time < b.arrival_time;
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
    }

    // Sort processes by arrival time
    std::sort(processes.begin(), processes.end(), compareByArrival);

    int time = 0;
    std::cout << "\nProcess Execution Order (FCFS):\n";
    for (const auto& p : processes) {
        if (time < p.arrival_time)
            time = p.arrival_time; // Wait for the process to arrive
        time += p.burst_time;      // Execute the process
        std::cout << "P" << p.id << " (Arrival: " << p.arrival_time
                  << ", Burst: " << p.burst_time << ")\n";
    }

    return 0;
}
