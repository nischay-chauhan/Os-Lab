#include <bits/stdc++.h>
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

bool compareArrivalTime(const Process& a, const Process& b) {
    return a.arrivalTime < b.arrivalTime;
}

int main(){
    int n;
    cout << "Enter the number of processes you want: ";
    cin >> n;

    vector<Process> processes(n);
    cout << "Enter process details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":\n";
        processes[i].id = i + 1;
        cout << "   Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "   Burst Time: ";
        cin >> processes[i].burstTime;
        cout << "   Priority: ";
        cin >> processes[i].priority;
    }
    
    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;
    int completedProcesses = 0;

    while(completedProcesses < n){
        int selectedProcess = -1;
        int maxPriority = INT_MAX;
        for(int i = 0;i<n;i++){
            if(processes[i].arrivalTime <= currentTime && processes[i].burstTime > 0){
                if(processes[i].priority < maxPriority){
                    maxPriority = processes[i].priority;
                    selectedProcess = i;
                }
                if(processes[i].priority == maxPriority){
                    if(processes[i].arrivalTime < processes[selectedProcess].arrivalTime){
                        maxPriority = processes[i].priority;
                        selectedProcess = i;
                    }
                }
            }
        }
         if(selectedProcess != -1){
                processes[selectedProcess].burstTime--;
                currentTime++;
                if(processes[selectedProcess].burstTime == 0){
                    processes[selectedProcess].completionTime = currentTime ;
                    processes[selectedProcess].turnaroundTime = processes[selectedProcess].completionTime - processes[selectedProcess].arrivalTime;
                    processes[selectedProcess].waitingTime = processes[selectedProcess].turnaroundTime - processes[selectedProcess].burstTime;
                    completedProcesses++;
                }
            }else{
                currentTime++;
            }
    }

    for(int i = 0; i < n; i++){
        cout << "Process " << processes[i].id << ":\n";
        cout << "   Completion Time: " << processes[i].completionTime << endl;
        cout << "   Turnaround Time: " << processes[i].turnaroundTime << endl;
        cout << "   Waiting Time: " << processes[i].waitingTime << endl;
    }

    return 0;
}