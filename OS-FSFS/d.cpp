/** 
 * Schedules processes based on the entry of the arrival time of the process
 * Calculates and prints the completion time, turnaround time, and waiting time for each process
 */

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
            return a < b;
        }
    });

    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;

    for (int i = 0; i < n; i++) {
        int index = processOrder[i];
        completionTime = max(completionTime, arrivalTime[index]) + burstTime[index];
        int turnaroundTime = completionTime - arrivalTime[index];
        int waitingTime = turnaroundTime - burstTime[index];
        cout << "Completion time of process " << index + 1 << " is " << completionTime << ", Turnaround time: " << turnaroundTime << ", Waiting time: " << waitingTime << endl;
    }
    cout << "Process Ended" << endl;
}