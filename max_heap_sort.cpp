#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void maxHeapSort(vector<int>& arr) {
    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
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
    maxHeapSort(arr);
    auto end = high_resolution_clock::now();

    cout << "Sorted array using Max Heap: ";
    for (int x : arr)
        cout << x << " ";

    auto duration = duration_cast<microseconds>(end - start);
    cout << "\nExecution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}
