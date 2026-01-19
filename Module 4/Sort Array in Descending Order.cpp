#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {5, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort array in descending order
    sort(arr, arr + n, greater<int>());

    for (int i : arr)
        cout << i << " ";

    return 0;
}