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

void merge(vector<int>& arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by Merge Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}