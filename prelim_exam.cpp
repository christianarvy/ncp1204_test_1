#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void insertToStack(stack<int>& s, const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        s.push(arr[i]);
    }
}

void insertToQueue(queue<int>& q, const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        q.push(arr[i]);
    }
}

void displayArray(const vector<int>& arr, const string& label) {
    cout << "\n=== " << label << " ===" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayStack(stack<int> s, const string& label) {
    cout << "\n=== " << label << " ===" << endl;
    if (s.empty()) {
        cout << "Stack is empty!" << endl;
    } else {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
}

void displayQueue(queue<int> q, const string& label) {
    cout << "\n=== " << label << " ===" << endl;
    if (q.empty()) {
        cout << "Queue is empty!" << endl;
    } else {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
}

void displayVector(const vector<int>& arr, const string& label) {
    cout << "\n=== " << label << " ===" << endl;
    if (arr.empty()) {
        cout << "Vector is empty!" << endl;
    } else {
        for (int val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<int> copyToVector(stack<int> s) {
    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

vector<int> copyToVector(queue<int> q) {
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

int main() {
    cout << "   PRELIM EXAM" << endl;
    srand(time(0));
    
    vector<int> originalArray(10);
    for (int i = 0; i < 10; i++) {
        originalArray[i] = 20 + rand() % 41; 
    }
    
    displayArray(originalArray, "TASK 1: Original Array (10 elements, 20-60)");

    stack<int> myStack;
    queue<int> myQueue;
    
    insertToStack(myStack, originalArray);
    insertToQueue(myQueue, originalArray);
    
    cout << "\n--- Before popping from stack ---" << endl;
    cout << "Stack size: " << myStack.size() << endl;
    cout << "Queue size: " << myQueue.size() << endl;
    
    cout << "\n--- Popping 3 times from stack ---" << endl;
    for (int i = 0; i < 3; i++) {
        if (!myStack.empty()) {
            cout << "Popped: " << myStack.top() << endl;
            myStack.pop();
        }
    }
    displayStack(myStack, "TASK 2: Remaining Stack Content (after 3 pops)");
    displayQueue(myQueue, "TASK 2: Queue Content (all 10 elements)");
    
    cout << "\n--- Popping 3 more times from stack (total 6 pops) ---" << endl;
    for (int i = 0; i < 3; i++) {
        if (!myStack.empty()) {
            cout << "Popped: " << myStack.top() << endl;
            myStack.pop();
        }
    }
    cout << "\n--- Stack after total of 6 pops ---" << endl;
    if (!myStack.empty()) {
        cout << "Stack size: " << myStack.size() << endl;
    } else {
        cout << "Stack is empty!" << endl;
    }
     
    cout << "   TASK 3: DATA MERGING" << endl;
    vector<int> mergedData; 
    stack<int> stackForMerge;
    queue<int> queueForMerge;
    insertToStack(stackForMerge, originalArray);
    insertToQueue(queueForMerge, originalArray);
    for (int i = 0; i < 6; i++) {
        if (!stackForMerge.empty()) {
            stackForMerge.pop();
        }
    }
    vector<int> tempStack;
    while (!stackForMerge.empty()) {
        tempStack.push_back(stackForMerge.top());
        stackForMerge.pop();
    }
    
    vector<int> tempQueue;
    while (!queueForMerge.empty()) {
        tempQueue.push_back(queueForMerge.front());
        queueForMerge.pop();
    }
    for (int val : tempStack) mergedData.push_back(val);
    for (int val : tempQueue) mergedData.push_back(val);
    
    displayVector(mergedData, "Merged Data ");
    cout << "Total elements: " << mergedData.size() << endl;
        

    cout << "   TASK 4 & 5: SORTING ALGORITHMS" << endl;
    cout << "   WITH TIME COMPLEXITY ANALYSIS" << endl;
    
    vector<long long> sortTimes;
    vector<string> sortNames = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort"};
    
    {
        vector<int> arr = mergedData;
        auto start = chrono::high_resolution_clock::now();
        bubbleSort(arr);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        sortTimes.push_back(duration.count());
        displayVector(arr, "Bubble Sort Result");
        cout << "Time: " << duration.count() << " microseconds" << endl;
    }
    
    {
        vector<int> arr = mergedData;
        auto start = chrono::high_resolution_clock::now();
        selectionSort(arr);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        sortTimes.push_back(duration.count());
        displayVector(arr, "Selection Sort Result");
        cout << "Time: " << duration.count() << " microseconds" << endl;
    }
    
 
    {
        vector<int> arr = mergedData;
        auto start = chrono::high_resolution_clock::now();
        insertionSort(arr);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        sortTimes.push_back(duration.count());
        displayVector(arr, "Insertion Sort Result");
        cout << "Time: " << duration.count() << " microseconds" << endl;
    } 
   
    {
        vector<int> arr = mergedData;
        auto start = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        sortTimes.push_back(duration.count());
        displayVector(arr, "Merge Sort Result");
        cout << "Time: " << duration.count() << " microseconds" << endl;
    }
    
    cout << "   CONCLUSION: TIME COMPLEXITY ANALYSIS" << endl;    
    cout << "\nSorting Algorithm Performance (14 elements):" << endl;
    
    for (int i = 0; i < sortNames.size(); i++) {
        double ms = sortTimes[i] / 1000.0; 
        cout << sortNames[i] << ": " << ms << " ms (" << sortTimes[i] << " microseconds)" << endl;
    }
    int minIdx = 0;
    for (int i = 1; i < sortTimes.size(); i++) {
        if (sortTimes[i] < sortTimes[minIdx]) {
            minIdx = i;
        }
    }
    ;
    cout << "Fastest Algorithm: " << sortNames[minIdx] << endl;
    cout << "   PROGRAM COMPLETED " << endl; 
    return 0;
}

