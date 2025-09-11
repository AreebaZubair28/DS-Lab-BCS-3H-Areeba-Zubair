#include "iostream"
using namespace std;

void InsertionSort(int* arr, int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j= i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void BinarySearch(int* arr, int n) {
    int target;
    cout << "\n\nEnter target value: "; cin>>target;

    int left = 0, right = n-1;
    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == target) {
            cout << "Value is found at index: " << mid << endl;
            return;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid -1;
        }
    }
    cout << "Value is not found";
}

void printArray(int* arr, int n) {
    cout<<"[ ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout<<"]";
}

int main() {
    int size;
    cout << "Enter size of array: "; cin>>size;

    int * arr = new int[size];
    for(int i=0; i<size; i++) {
        cout << "Element " << i+1 << ": ";  cin>>arr[i];
    }

    InsertionSort(arr, size);

    cout << "\nSorted Array: ";
    printArray(arr, size);

    BinarySearch(arr, size);

    delete[] arr;
}