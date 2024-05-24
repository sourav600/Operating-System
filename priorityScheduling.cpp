#include<iostream>
#include<algorithm>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

bool compareArrivalTime(Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
}

bool comparePriority(Process a, Process b) {
    return a.priority < b.priority;
}

void calculateTimes(Process processes[], int n) {
    processes[0].completionTime = processes[0].arrivalTime + processes[0].burstTime;
    processes[0].turnaroundTime = processes[0].completionTime - processes[0].arrivalTime;
    processes[0].waitingTime = processes[0].turnaroundTime - processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        processes[i].completionTime = processes[i - 1].completionTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

void displayTable(Process processes[], int n) {
    cout << "Process AT\tBT\tPriority CT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t"
             << processes[i].burstTime << "\t" << processes[i].priority << "\t\t "
             << processes[i].completionTime << "\t " << processes[i].turnaroundTime << "\t "
             << processes[i].waitingTime << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../Input.txt", "r", stdin);
    freopen("../Output.txt", "w", stdout);
    #endif
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];

    cout << "Enter arrival time, burst time, and priority for each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> processes[i].burstTime;
        cout << "Process " << i + 1 << " Priority: ";
        cin >> processes[i].priority;
    }

    // Sort processes based on arrival time (if not already sorted)
    sort(processes, processes + n, compareArrivalTime);

    // Sort processes based on priority for Priority Scheduling
    sort(processes, processes + n, comparePriority);

    calculateTimes(processes, n);

    cout << "\nPriority Scheduling Results:\n";
    displayTable(processes, n);

    return 0;
}
