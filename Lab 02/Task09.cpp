#include "iostream"
using namespace std;

int main() {
    int r;
    int c;

    cout << "Enter rows: ";     cin>>r;
    cout << "Enter columns: ";  cin>>c;

    int ** matrix = new int*[r];
    cout << endl;
    for(int i=0; i<r; i++) {
        matrix[i] = new int[c];
        cout << "Row " << i+1 << endl;
        for(int j=0; j<c ; j++) {
            cout << "Column " << j+1 << ": ";
            cin >> matrix[i][j];
        }
    }

    cout << "\n ------------ Matrix in Normal Form ------------" << endl;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n ------------ Matrix in Compressed Form ------------" << endl;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) { 
            if (matrix[i][j] != 0) {
                cout << "Row: " << i+1 << ", Column: " << j+1 << ", Value: " << matrix[i][j] << endl;
            }
        }
        cout << endl;
    }

    for(int i=0; i<r; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}