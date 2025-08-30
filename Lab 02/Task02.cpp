#include"iostream"
using namespace std;

int main() {
    int row;
    int col;

    cout << "Enter row: "; cin>>row;
    cout << "Enter columns: " ; cin >>col;

    int** arr = new int*[row];
    for(int i=0; i<row; i++) {
        arr[i] = new int[col]{0};
    }

    int bench;
    int seat;
    string choise;
    do{
        cout << "Enter bench: "; cin>>bench;
        if(bench > 0 && bench-1 < row) {
            cout << "Enter seat: "; cin>>seat;
            if(seat > 0 && seat-1 < col) {
                arr[bench-1][seat-1] = 1;
                cout << "Bench " << bench << ", Seat " << seat << " is occupied.\n";
            }else {
            cout << "Invalid seat." << endl;
            }
        }else {
            cout << "Invalid bench." << endl;
        }

        cout<<"Do you want to fill any other seat(yes/no): ";
        cin>>choise;
    }while(choise == "yes");

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    for(int i=0; i<row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
