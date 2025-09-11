#include "iostream"
using namespace std;

void printArray(int* arr, int n) {
    cout<<"[ ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout<<"]";
}

void CombSort(int* arr, int n) {
    float shrink = 1.3;
    int gap = n;
    bool swapped = true;

    int compare = 0, swaps = 0;
   
    while(gap>1 || swapped) {
        gap = (int)(gap/shrink);
        if(gap<1) {
            gap = 1;
        }
        swapped = false;
       
        for(int i=0 ; i+gap<n ; i++) {
            compare++;
            if(arr[i] > arr[i+gap]) {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;
                swapped = true;
                swaps++;
            }
       
        }
    }

    cout << "\nSorted Array: ";
    printArray(arr, n);
    cout << "\nNumber of comparisons: " << compare << endl;
    cout << "Number of swaps: " << swaps << endl;
}

int main() {
    int size;
    cout << "Enter size of array: "; cin>>size;

    cout << "Enter array\n";
    int * arr = new int[size];
    for(int i=0; i<size; i++) {
        cout << "Element " << i+1 << ": ";  cin>>arr[i];
    }

    cout << "\nUnsorted Array: ";
    printArray(arr, size);

    CombSort(arr, size);

    delete[] arr;
}