/** Shortest Job First SJF in this firstly the process that have the minimun arrival time neter the cpu and after the process has finished executing it check what other process have come under in the ready queue to be executed next if the completion time of the first process is less than the arrival time of the next process then the process which have the less arrival time in the lot of other process is executed first and then checked again otherwise if the arrival time of the other process is less than the completion time of the first process it then the process are sorted in the order of their burst size and then are exectuted in ascending order of their burst time  */

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes you want: ";
    cin >> n;
    vector<int> arrivalTime(n);
    vector<int> burstTime(n);
    vector<int> processOrder(n);
    int completionTime = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time of process " << i + 1 << " : ";
        cin >> arrivalTime[i];
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> burstTime[i];
        processOrder[i] = i;
    }

   sort(processOrder.begin(), processOrder.end(), [&](int a, int b) {
       if (arrivalTime[a] != arrivalTime[b]) {
           return arrivalTime[a] < arrivalTime[b];
       } else {
           return burstTime[a] < burstTime[b];
       }
   });


    sort(processOrder.begin() + 1, processOrder.end(), [&](int a, int b) {
        if(burstTime[a] != burstTime[b]) {
            return burstTime[a] < burstTime[b];
        } else {
            return arrivalTime[a] < arrivalTime[b];
        }
    });



    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        int index = processOrder[i];
        currentTime = max(currentTime, arrivalTime[index]);
        int startExecutionTime = currentTime;
        currentTime += burstTime[index];
        int completionTime = currentTime;
        int turnaroundTime = completionTime - arrivalTime[index];
        int waitingTime = startExecutionTime - arrivalTime[index];

        cout << "Completion time of process " << index + 1 << " is " << completionTime << ", Turnaround time: " << turnaroundTime << ", Waiting time: " << waitingTime << endl;
    }

    cout << "SJF Scheduling Ended" << endl;
}