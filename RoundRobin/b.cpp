#include <iostream>
using namespace std;
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(Process processes[], int n, int quantum) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
    }
    int currentTime = 0;
    bool allDone = false;
    while (!allDone) {
        allDone = true;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                allDone = false;
                if (remainingTime[i] > quantum) {
                    currentTime = currentTime + quantum;
                    remainingTime[i] = remainingTime[i] - quantum;
                } else {
                    currentTime = currentTime + remainingTime[i];
                    processes[i].completionTime = currentTime;
                    remainingTime[i] = 0;
                }
            }
        }
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaroundTime =
            processes[i].completionTime - processes[i].arrivalTime;
}

void calculateWaitingTime(Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].waitingTime =
            processes[i].turnaroundTime - processes[i].burstTime;
}

void printTable(Process processes[], int n) {
    cout << "Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << "   " << processes[i].id << "    |      "
             << processes[i].arrivalTime << "      |     " << processes[i].burstTime
             << "     |        " << processes[i].completionTime
             << "        |        " << processes[i].turnaroundTime
             << "         |      " << processes[i].waitingTime << endl;
    }
}

int main() {
    int n, quantum;
    cout << "Enter The Number of Process: ";
    cin >> n;
    cout << "Enter The Time Quantum: ";
    cin >> quantum;

    Process processes[n];
    cout << "Enter process details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":\n";
        processes[i].id = i + 1;
        cout << "   Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "   Burst Time: ";
        cin >> processes[i].burstTime;
    }

    calculateTimes(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    calculateWaitingTime(processes, n);

    cout << "\nRound Robin Scheduling Results:\n";
    printTable(processes, n);

    return 0;
}
