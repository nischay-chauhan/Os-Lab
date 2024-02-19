/* First approach for the shortest job first using with the non primitive method and using vectors but later optimised in next file by defining a structure  */
#include <iostream>
#include <vector>
#include <algorithm>
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

    int currentTime = arrivalTime[processOrder[0]];
    int totaltimeofP1 = arrivalTime[processOrder[0]] + burstTime[processOrder[0]];

    sort(processOrder.begin() + 1, processOrder.end(), [&](int a, int b) {
        if (burstTime[a] != burstTime[b]) {
            return burstTime[a] < burstTime[b];
        } else {
            return arrivalTime[a] < arrivalTime[b];
        }
    });

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        int index = processOrder[i];
        int startExecutionTime = currentTime;
        currentTime += burstTime[index];
        int completionTime = currentTime;
        int turnaroundTime = completionTime - arrivalTime[index];
        int waitingTime = startExecutionTime - arrivalTime[index];

        cout << "Completion time of process " << index + 1 << " is " << completionTime << ", Turnaround time: " << turnaroundTime << ", Waiting time: " << waitingTime << endl;
    }

    cout << "SJF Scheduling Ended" << endl;
}