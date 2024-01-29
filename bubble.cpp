#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
void bubble_sort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    srand(time(0));
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    auto start_time = chrono::high_resolution_clock::now();

    bubble_sort(arr);

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    cout << "Time taken for sorting: " << duration << " microseconds" << endl;

    return 0;
}