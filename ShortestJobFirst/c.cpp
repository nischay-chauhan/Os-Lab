#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

bool compareArrivalTime(const Process& a, const Process& b) {
    return a.arrivalTime < b.arrivalTime;
}

bool compareBurstTime(const Process& a, const Process& b) {
    return a.burstTime < b.burstTime;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;

    while (!processes.empty()) {
        sort(processes.begin(), processes.end(), compareBurstTime);

        bool processExecuted = false;

        for (int i = 0; i < processes.size(); ++i) {
            if (processes[i].arrivalTime <= currentTime) {
                processes[i].completionTime = currentTime + processes[i].burstTime;
                processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
                processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
                currentTime = processes[i].completionTime;
                cout << "Process " << processes[i].id << "\tCompletion Time: " << processes[i].completionTime
                     << "\tTurnaround Time: " << processes[i].turnaroundTime << "\tWaiting Time: " << processes[i].waitingTime << endl;
                processes.erase(processes.begin() + i);
                processExecuted = true;
                break;
            }
        }

        if (!processExecuted) {
            currentTime++;
        }
    }

    return 0;
}
