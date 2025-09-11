#include "iostream"
using namespace std;

void SearchValue(int * arr, int n) {
    int target;
    int index;
    bool flag = 0;
    cout << "\n\nEnter target value: "; cin>>target;

    for(int i=0; i<n; i++) {
        if(target == arr[i]) {
            index = i;
            flag = 1;
            cout << "Value is found at index: " << index;
            break;
        }
    }
    if(!flag) { cout << "Value is not found"; }
}

int main() {
    int size;
    cout << "Enter size of array: "; cin>>size;

    int * arr = new int[size];
    for(int i=0; i<size; i++) {
        cout << "Element " << i+1 << ": ";  cin>>arr[i];
    }

    cout << "\nArray: ";
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }

    SearchValue(arr, size);

    delete[] arr;
}
