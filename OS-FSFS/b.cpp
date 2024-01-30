/** first it checks the arrival time then it check the burst time if the arrival time is same and give priority to the one with less burst time */

#include <bits/stdc++.h>
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

    for (int i = 0; i < n; i++) {
        int index = processOrder[i];
        completionTime = max(completionTime, arrivalTime[index]) + burstTime[index];
        cout << "Completion time of process " << index + 1 << " is " << completionTime << endl;
    }
    cout << "Process Ended" << endl;
}