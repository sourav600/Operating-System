#include<iostream>
#include<queue>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(Process processes[], int n, int quantum) {
    queue<int> readyQueue;
    int currentTime = 0;
    int remainingProcesses = n;

    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                int executionTime = min(quantum, processes[i].remainingTime);
                processes[i].remainingTime -= executionTime;
                currentTime += executionTime;

                if (processes[i].remainingTime == 0) {
                    processes[i].completionTime = currentTime;
                    processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
                    processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
                    remainingProcesses--;
                }

                readyQueue.push(i);
            }
        }
    }
}

void displayTable(Process processes[], int n) {
    cout << "Process AT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t"
             << processes[i].burstTime << "\t" << processes[i].completionTime << "\t"
             << processes[i].turnaroundTime << "\t" << processes[i].waitingTime << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../Input.txt", "r", stdin);
    freopen("../Output.txt", "w", stdout);
    #endif
    int n, quantum;
    cin >> n>> quantum;

    Process processes[n];

    // cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cin >> processes[i].arrivalTime;
        cin >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    calculateTimes(processes, n, quantum);

    cout << "\nRound Robin Scheduling Results:\n";
    displayTable(processes, n);

    return 0;
}
