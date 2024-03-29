#include <bits/stdc++.h>

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

int main(){
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
    int completedProcesses = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    while(completedProcesses < n){
        int selectedProcess = -1;
        int minBurstTime = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if(processes[i].arrivalTime <= currentTime && processes[i].burstTime > 0){
                if(processes[i].burstTime < minBurstTime){
                    minBurstTime = processes[i].burstTime;
                    selectedProcess = i;
                }
            }
        }

        if(selectedProcess == -1){
            currentTime++;
        } else {
            currentTime++;
            processes[selectedProcess].burstTime--;

            if(processes[selectedProcess].burstTime == 0){
                completedProcesses++;
                processes[selectedProcess].completionTime = currentTime;
                processes[selectedProcess].turnaroundTime = processes[selectedProcess].completionTime - processes[selectedProcess].arrivalTime;
                processes[selectedProcess].waitingTime = processes[selectedProcess].turnaroundTime - processes[selectedProcess].burstTime;

                totalWaitingTime += processes[selectedProcess].waitingTime;
                totalTurnaroundTime += processes[selectedProcess].turnaroundTime;
            }
        }
    }

    cout << "Process\t \tCompletion Time \tWaiting Time\t Turnaround Time" << endl;
    for (const auto& p : processes) {
        cout << p.id << "\t\t" << p.completionTime << "\t\t\t" << p.waitingTime << "\t\t\t" << p.turnaroundTime << endl;
    }

    cout << "Average Waiting Time: " << (double) totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << (double) totalTurnaroundTime / n << endl;

    return 0;
}