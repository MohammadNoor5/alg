#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (const int& val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    auto start = chrono::high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by Quick Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}