/* Least Recently used page replacement */
#include<bits/stdc++.h>
using namespace std;

void LRUPageReplacement(vector<int>& pages, int capacity) {
    deque<int> pageStack;
    unordered_map<int, bool> pageMap;
    int pageFaults = 0;
    int hit = 0;
    
    for (int page : pages) {
        if (pageMap.find(page) != pageMap.end()) {
            pageStack.pop_back();
            pageMap.erase(pageStack.back());
            pageStack.push_front(page);
            pageMap[page] = true;
            hit++;
        } else {
            if (pageStack.size() == capacity) {
                pageMap.erase(pageStack.back());
                pageStack.pop_back();
            }
            pageFaults++;
            pageStack.push_front(page);
            pageMap[page] = true;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    cout << "Total Hits: " << hit << endl;
    cout << "Elements present in the stack:" << endl;
    while (!pageStack.empty()) {
        cout << pageStack.front() << " ";
        pageStack.pop_back();
    }
}

int main() {
    vector<int> pages = {5,0,1,2,0,3,2,0,3,4,1,0,5,0,4,3,2,1,2,0,1};
    int capacity = 3;
    LRUPageReplacement(pages, capacity);

    return 0;
}