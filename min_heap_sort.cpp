#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void minHeapSort(vector<int>& arr) {
    int n = arr.size();

    // Build Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    // Reverse to get ascending order
    reverse(arr.begin(), arr.end());
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto start = high_resolution_clock::now();
    minHeapSort(arr);
    auto end = high_resolution_clock::now();

    cout << "Sorted array using Min Heap: ";
    for (int x : arr)
        cout << x << " ";

    auto duration = duration_cast<microseconds>(end - start);
    cout << "\nExecution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}
