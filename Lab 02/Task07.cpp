#include"iostream"
using namespace std;

void highestSalar(int ** arr, int rows, int * cols) {
    int * high = new int[rows]{0};

    cout << "\n ----------- Highest Salaries of each Department -----------";
    for(int i=0; i<rows; i++) {
        cout << "\nDepartment " << i+1 << ": $";
        for(int j=0; j<cols[i]; j++) {
            if(high[i] < arr[i][j]) {
                high[i] = arr[i][j];
            }
        }
        cout << high[i];
    }

    cout << endl;

    delete[] high;
}

void MaxAvg(int ** arr, int rows, int * cols) {
    float * avg = new float[rows];
    float maxAvg = 0;
    int depart;
    float sum = 0.0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols[i]; j++) {
            sum += arr[i][j];
        }
        avg[i] = sum / cols[i];

        if(maxAvg < avg[i]) {
            maxAvg = avg[i];
            depart = i+1;
        }
        sum = 0.0;
    }

    cout << "\nDepartment with maximum average salary of $" << maxAvg << " is " << depart << endl;
    
    delete[] avg;
}

int main() {
    int rows;

    cout << "Total Departments: ";   cin>>rows;
    int ** depart = new int*[rows];
    int * emps = new int[rows];

    for(int i=0; i<rows; i++) {
        cout << "\nNo. Employess of Department " << i+1 << ": ";
        cin >> emps[i];
        depart[i] = new int[emps[i]];

        for(int j=0; j<emps[i]; j++) {
            cout << "Salary of employe " << j+1 << ": $";
            cin >> depart[i][j];
        }
    }

    highestSalar(depart, rows, emps);
    MaxAvg(depart, rows, emps);

    for(int i=0; i<rows; i++) {
        delete[] depart[i];
    }
    delete[] depart;
    delete[] emps;
}
