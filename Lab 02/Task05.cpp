#include"iostream"
using namespace std;

int** createMatrix(int rows, int cols) {
    int ** arr = new int*[rows];
    for(int i=0; i<rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}

void inputMatrix(int** arr, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        cout << "\nrow " << i+1 << endl;
        for(int j=0; j<cols; j++) {
            cout << "column " << j+1 << ": ";    cin >> arr[i][j];
        }
    }
}

void print(int** arr, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << arr[i][j] << "  ";
        }
        cout<<endl;
    }
}

void deleteArray(int** arr, int rows) {
    for(int i=0; i<rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    cout << "Deleted\n";
}

int main() {
    int rows[2];
    int cols[2];

    for(int i=0; i<2; i++) {
        cout << "Enter rows for matrix " << i+1 << ": ";
        cin >> rows[i];
        cout << "Enter columns for matrix " << i+1 << ": ";
        cin >> cols[i];
        cout << endl;
    }
   
    int ** matrix_1 = createMatrix(rows[0], cols[0]);
    int ** matrix_2 = createMatrix(rows[1], cols[1]);

    cout << " ------ Matrix 1 ------";
    inputMatrix(matrix_1, rows[0], cols[0]);

    cout << "\n ------ Matrix 2 ------";
    inputMatrix(matrix_2, rows[1], cols[1]);

    cout << "\nMatrix 1\n";
    print(matrix_1, rows[0], cols[0]);
    
    cout << "\nMatrix 2\n";
    print(matrix_2, rows[1], cols[1]);

    // Addition
    if(rows[0] == rows[1] && cols[0] == cols[1]) {
        cout << "\nAddition of matrices is possible\n";

        int ** add = createMatrix(rows[0], cols[0]);
        for(int i=0; i<rows[0]; i++) {
            for(int j=0; j<cols[0]; j++) {
                add[i][j] = matrix_1[i][j] + matrix_2[i][j];
            }
        }
        print(add, rows[1], cols[1]);

        cout << "Addition Matrix ";
        deleteArray(add, rows[0]);
    }else{
        cout << "\nAddition of matrices is not possible\n";
    }

    // Subtraction
    if(rows[0] == rows[1] && cols[0] == cols[1]) {
        cout << "\nSubtraction of matrices is possible\n";

        int ** sub = createMatrix(rows[0], cols[0]);
        for(int i=0; i<rows[0]; i++) {
            for(int j=0; j<cols[0]; j++) {
                sub[i][j] = matrix_1[i][j] - matrix_2[i][j];
            }
        }
        print(sub, rows[1], cols[1]);

        cout << "Subtraction Matrix ";
        deleteArray(sub, rows[0]);
    }else{
        cout << "Subtraction of matrices is not possible\n";
    }

    cout << "\nMatrix 1 ";
    deleteArray(matrix_1, rows[0]);
    cout << "Matrix 2 ";
    deleteArray(matrix_2, rows[1]);
}
