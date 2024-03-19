#include<bits/stdc++.h>
using namespace std;

struct Process{
    int id;
    vector<int> Allocation = vector<int>(3);
    vector<int> Maximum = vector<int>(3);
    vector<int> Need = vector<int>(3);
    int Available = 1;
    vector <int> AvailableTime = vector<int>(3);
};

int main(){

    int Available1 = 335;
    int n = 5;
    vector<Process> processes(n);

    processes[0].id = 1;
    processes[0].Allocation = {0, 1, 0};
    processes[0].Maximum = {7, 5, 3};

    processes[1].id = 2;
    processes[1].Allocation = {2, 0, 0};
    processes[1].Maximum = {3, 2, 2};

    processes[2].id = 3;
    processes[2].Allocation = {3, 0, 2};
    processes[2].Maximum = {9, 0, 2};

    processes[3].id = 4;
    processes[3].Allocation = {2, 1, 1};
    processes[3].Maximum = {2, 2, 2};

    processes[4].id = 5;
    processes[4].Allocation = {0, 0, 2};

    // Finding the need for each process
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            processes[i].Need[j] = processes[i].Maximum[j] - processes[i].Allocation[j];
        }
    }

    vector<int> work = {3, 3, 5};
    vector<int> safeSequence;

    bool completed = false;
    while(!completed){
        completed = true; 
        for(int i = 0; i < n; i++){
            if(processes[i].Available == 1){
                bool canFinish = true;
                for(int j = 0; j < 3; j++){
                    if(processes[i].Need[j] > work[j]){
                        canFinish = false;
                        break;
                    }
                }
                if(canFinish){
                    safeSequence.push_back(processes[i].id - 1);
                    processes[i].Available = 0;
                    for(int j = 0; j < 3; j++){
                        work[j] += processes[i].Allocation[j];
                        processes[i].AvailableTime[j] = work[j];
                    }
                    completed = false; 
                }
            }
        }
    }

    for(int i = 0; i < safeSequence.size(); i++){
        cout << safeSequence[i] << " " << endl;
    }

    for(int i = 0; i < n; i++){
        cout << "The Available Time for process " << processes[i].id << " is ";
        for(int j = 0; j < processes[i].AvailableTime.size(); j++){
            cout << processes[i].AvailableTime[j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}