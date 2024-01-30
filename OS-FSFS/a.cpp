/** Basic FCFS(first come first served) scheduling algorithm that executes the process on the basis of the arrival time of the process*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes you want: ";
    cin >> n;
    vector<int> arrivalTime(n);
    vector<int> DontTouchThis(n);
    vector<int> burstTime(n);
    int completionTime = 0;
    // AT 0 , 1 , 1 , 2 in such cases i want tto compare the burst time and the one with less burst time get higher priority in copletion time
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time of process " << i + 1 << " : ";
        cin >> arrivalTime[i];
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> burstTime[i];
    }
    DontTouchThis = arrivalTime;

    for (int i = 0; i < n; i++) {
        completionTime = arrivalTime[i] + burstTime[i];
        if (i < n - 1 && completionTime > arrivalTime[i + 1]) {
            arrivalTime[i + 1] = completionTime;
            cout << "Completion time of " << DontTouchThis[i] << " is " << completionTime << endl;
        } else {
            cout << "Completion time of " << DontTouchThis[i] << " is " << arrivalTime[i] + burstTime[i] << endl;
        }
    }
    cout << "Process Ended" << endl;
}

