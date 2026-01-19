#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 5, 8, 1, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort only the elements from index 1 to 4 (i.e., 5, 8, 1, 7)
    sort(arr + 1, arr + 5);

    // Print the array after sorting the range
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}