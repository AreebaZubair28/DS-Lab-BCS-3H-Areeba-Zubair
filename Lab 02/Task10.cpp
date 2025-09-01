#include "iostream"
using namespace std;

void search(int** arr, int r, int* c, string* cat, int id) {
    bool flag = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c[i]; j++) {
            if( id == arr[i][j]) {
                flag =1;
                cout << "Book with ID: " << id << " is Available in " << cat[i] << " category\n";
            }
        }
    }
    if(!flag) { 
        cout << "Book with ID: " << id << " is not Available.\n"; 
    }
}

int main() {
    int category;

    cout << "Enter no. categories: ";     cin>>category;

    int ** library = new int*[category];
    int * books  = new int[category];
    string * CatName  = new string[category];
    cout << endl;
    for(int i=0; i<category; i++) {
        cout << "Name of category " << i+1 << ": ";
        cin >> CatName[i];
        cout << "No. book: ";  cin>>books[i];
        library[i] = new int[books[i]];
    
        for(int j=0; j<books[i] ; j++) {
            cout << "Id of Book " << j+1 << ": ";
            cin >> library[i][j];
        }
        cout << endl;
    }

    search(library, category, books, CatName, 01);

    for(int i=0; i<category; i++) {
        delete[] library[i];
    }
    delete[] library;
    delete[] books;
    delete[] CatName;
}
