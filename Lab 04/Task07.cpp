#include <iostream>
#include <chrono>   
#include <cstdlib>  
#include <ctime>
using namespace std;
using namespace std::chrono;

void ShellSort(int* arr, int n) {
    int compare = 0, swaps = 0;
    auto start = high_resolution_clock::now();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int j = gap; j < n; j++) {
            int key = arr[j];
            int res = j;

            while (res >= gap) {
                compare++; 
                if (arr[res - gap] > key) {
                    arr[res] = arr[res - gap];
                    swaps++;
                    res -= gap;
                } else {
                    break;
                }
            }
            arr[res] = key;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nDuring Shell Sort\n";
    cout << "No. Comparisons: " << compare << endl;
    cout << "No. Swaps: " << swaps << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
}

void BubbleSort(int* arr, int n) {
    int compare = 0, swaps = 0;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            compare++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nDuring Bubble Sort\n";
    cout << "No. Comparisons: " << compare << endl;
    cout << "No. Swaps: " << swaps << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
}

void InsertionSort(int* arr, int n) {
    int compare = 0, swaps = 0;
    auto start = high_resolution_clock::now();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            compare++; 
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nDuring Insertion Sort\n";
    cout << "No. Comparisons: " << compare << endl;
    cout << "No. Swaps: " << swaps << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
}

int main() {
    srand(time(0));
    int n = 10000; 
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    cout << "Sorting " << n << " random integers...\n";

    int* arr1 = new int[n];
    copy(arr, arr + n, arr1);
    ShellSort(arr1, n);

    int* arr2 = new int[n];
    copy(arr, arr + n, arr2);
    InsertionSort(arr2, n);

    int* arr3 = new int[n];
    copy(arr, arr + n, arr3);
    BubbleSort(arr3, n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}
