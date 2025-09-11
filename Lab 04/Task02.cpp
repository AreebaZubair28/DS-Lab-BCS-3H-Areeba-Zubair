#include "iostream"
using namespace std;

void BubbleSort(int* arr, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
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

    BubbleSort(arr, size);

    cout << "\nSorted Array: ";
    printArray(arr, size);

    delete[] arr;
}