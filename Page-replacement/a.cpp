#include <bits/stdc++.h>
using namespace std;

void FIFOPageReplacement(vector<int>& pages, int capacity) {
    queue<int> pageQueue;
    int pageFaults = 0;
    int hit = 0;
    for (int page : pages) {
        bool found = false;
        queue<int> temp = pageQueue;
        while (!temp.empty()) {
            if (temp.front() == page) {
                found = true;
                hit +=1;
                break;
            }
            temp.pop();
        }
        if (!found) {
            if (pageQueue.size() == capacity) {
                pageQueue.pop();
            }
            pageQueue.push(page);
            pageFaults++;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    cout << "Total Hits : " << hit << endl;
    cout << "Element present in the last queue" <<endl;
    while(!pageQueue.empty()){
        cout << pageQueue.front() << " " << endl;
        pageQueue.pop();
    }
    /* Alternatively you can use this
    cout << "Total Hits : " << pages.size() - pageFaults << endl;
     */
}

int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0};
    int capacity = 3;
    FIFOPageReplacement(pages, capacity);

    return 0;
}