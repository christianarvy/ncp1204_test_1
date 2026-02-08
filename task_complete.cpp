#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

// Function to insert array elements into stack
void insertToStack(stack<int>& s, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        s.push(arr[i]);
    }
}

// Function to insert array elements into queue
void insertToQueue(queue<int>& q, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        q.push(arr[i]);
    }
}

// Function to display array using for loop
void displayArray(int arr[], int size) {
    cout << "\n===== TASK 1: Display Array Content =====" << endl;
    cout << "Array elements (10 elements, values 20-60):" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

// Function to display stack with verification
void displayStack(stack<int> s) {
    cout << "\n===== TASK 2: Stack Display =====" << endl;
    
    if (s.empty()) {
        cout << "Stack is EMPTY - No content to display!" << endl;
    } else {
        cout << "Stack content (top to bottom): ";
        while (!s.empty()) {
            cout << s.top();
            s.pop();
            if (!s.empty()) cout << ", ";
        }
        cout << endl;
    }
}

// Function to display queue with verification
void displayQueue(queue<int> q) {
    cout << "\nQueue Display:" << endl;
    
    if (q.empty()) {
        cout << "Queue is EMPTY - No content to display!" << endl;
    } else {
        cout << "Queue content (front to back): ";
        while (!q.empty()) {
            cout << q.front();
            q.pop();
            if (!q.empty()) cout << ", ";
        }
        cout << endl;
    }
}

int main() {
    // Task 1: Create an integer array with 10 elements (values 20-60)
    int arr[10] = {45, 23, 58, 32, 61, 28, 55, 19, 42, 36};
    int size = 10;
    
    // Display array using for loop
    displayArray(arr, size);
    
    // Task 2: Create stack and queue containers
    stack<int> myStack;
    queue<int> myQueue;
    
    // Insert array elements into stack and queue
    cout << "\n===== Inserting array elements into Stack and Queue =====" << endl;
    insertToStack(myStack, arr, size);
    insertToQueue(myQueue, arr, size);
    cout << "Array elements inserted successfully!" << endl;
    
    // Display stack before popping
    cout << "\n--- Stack BEFORE popping 3 elements ---" << endl;
    stack<int> stackCopy = myStack;
    displayStack(stackCopy);
    
    // Pop 3 times from stack
    cout << "\n===== Popping 3 elements from Stack =====" << endl;
    for (int i = 0; i < 3; i++) {
        if (!myStack.empty()) {
            cout << "Popped: " << myStack.top() << endl;
            myStack.pop();
        } else {
            cout << "Stack is empty! Cannot pop more elements." << endl;
            break;
        }
    }
    
    // Display stack after popping with verification
    cout << "\n--- Stack AFTER popping 3 elements ---" << endl;
    displayStack(myStack);
    
    // Display queue with verification
    displayQueue(myQueue);
    
    cout << "\n===== Program Completed =====" << endl;
    
    return 0;
}
