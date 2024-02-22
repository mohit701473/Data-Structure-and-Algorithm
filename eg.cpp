#include<bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

struct Process {
    int id;
    int priority;
    int arrival_time;
    int burst_time;
};

// Comparator for sorting processes based on arrival time
struct CompareArrivalTime {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.arrival_time > p2.arrival_time;
    }
};

// Comparator for sorting processes based on priority
struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority > p2.priority;
    }
};

// Function to simulate FCFS scheduling for Input/Output devices
void fcfs_scheduling(queue<Process>& io_queue, int& current_time) {
    while (!io_queue.empty()) {
        Process p = io_queue.front();
        io_queue.pop();
        cout << "Process " << p.id << " (I/O) starts at time " << current_time << endl;
        current_time += p.burst_time; // Process device burst time
        cout << "Process " << p.id << " (I/O) ends at time " << current_time << endl;
    }
}

int main() {
    ifstream infile("input.txt");
    if (!infile) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }

    vector<Process> processes;
    priority_queue<Process, vector<Process>, CompareArrivalTime> arrival_queue;
    queue<Process> io_queue;
    int current_time = 0;

    // Read input file
    int id, priority, arrival_time, burst_time;
    char device;
    while (infile >> id >> priority >> arrival_time >> device >> burst_time) {
        processes.push_back({id, priority, arrival_time, burst_time});
    }

    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(), CompareArrivalTime());

    for (const auto& p : processes) {
        arrival_queue.push(p);
    }

    // Stride scheduling
    while (!arrival_queue.empty()) {
        Process current_process = arrival_queue.top();
        arrival_queue.pop();

        if (current_process.arrival_time > current_time) {
            current_time = current_process.arrival_time;
        }

        cout << "Process " << current_process.id << " (CPU) starts at time " << current_time << endl;
        current_time += current_process.burst_time; // Process CPU burst time
        cout << "Process " << current_process.id << " (CPU) ends at time " << current_time << endl;

        // Check for Input/Output device requests
        if (device == 'P') {
            fcfs_scheduling(io_queue, current_time); // Perform FCFS scheduling for Input/Output devices
        } else if (device == 'I' || device == 'O') {
            io_queue.push(current_process);
        }
    }

    // Process remaining processes in the I/O queue
    fcfs_scheduling(io_queue, current_time);

    return 0;
}
