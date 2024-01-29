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

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
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

    selectionSort(arr);

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by Selection Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}