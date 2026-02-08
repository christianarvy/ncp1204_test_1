#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <chrono>
using namespace std;

int main() {
    
    int arr[10] = {45, 25, 55, 35, 60, 23, 50, 21, 48, 30};
    
    cout << " TASK 1: ARRAY CREATION AND DISPLAY " << endl;
    cout << "\nOriginal Array (10 elements, unsorted):" << endl;
    cout << "Values range: 20-60" << endl;
    cout << "\n";

    cout << "Array Contents: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i];
        if (i < 9) cout << " , ";  
    }
    cout << endl;
   
    cout << "Values" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Index [" << i << "]: " << arr[i] << endl;
    }
        
    cout << "\n STACK AND QUEUE OPERATIONS " << endl;
  
    stack<int> actions;
    queue<int> printqueue;
  
    cout << "\nInserting array elements into stack and queue" << endl;
    for (int i = 0; i < 10; i++) {
        actions.push(arr[i]);
        printqueue.push(arr[i]);
    }
    cout << "\nPopping 3 elements from stack:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Popped: " << actions.top() << endl;
        actions.pop();
    }
    cout << "\nStack Contents (after 3 pops):" << endl;
    stack<int> tempStack = actions;  
    if (tempStack.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
    cout << "\nQueue Contents:" << endl;
    queue<int> tempQueue = printqueue;
    if (tempQueue.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    } 

vector<int> Mergeddata;
 
While(!actions.empty()) {
    Mergeddata.push_back(actions.top());
    actions.pop();
}

while(!printqueue.empty()) {
    Mergeddata.push_back(printqueue.front());
    printqueue.pop();
}

cout<<"total elements after merging: "<<Mergeddata.size()<<endl;
cout<<"Merged Data: ";
for(int val : Mergeddata) {
    cout<<val<<" ";
}
cout<<endl;

    