#include"iostream"
using namespace std;

int main() {
    int size;
    cout << "Enter size: ";   cin >> size;

    int *arr = new int[size]{0};

    int pos;
    string choise;
    do{
        cout << "Enter position to add value at: ";   cin >> pos;
        if(pos-1 < size) {
            cout << "Enter the value of element at postion " << pos << ": "; 
            cin >> arr[pos-1];
        } else{
            cout << "Invalid index" << endl;
        }

        cout<<"Do you want to add value(yes/no): ";
        cin>>choise;
     }while(choise == "yes");
    
    for(int i=0; i<size; i++) {
        cout << "Element " << i+1 << ": " << arr[i] << endl;
    }

    delete[] arr;
}
