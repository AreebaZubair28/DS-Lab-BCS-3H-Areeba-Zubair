#include "iostream"
using namespace std;

void SelectionSort(int* arr, int n) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
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

    cout << "\nUnsorted Array: ";
    printArray(arr, size);

    SelectionSort(arr, size);

    cout << "\nSorted Array: ";
    printArray(arr, size);

    delete[] arr;
}