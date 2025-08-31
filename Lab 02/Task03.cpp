#include"iostream"
using namespace std;

int main() {
    int students;
    cout << "Enter number of students: ";   cin>>students;

    int ** marks = new int*[students];

    int * courses = new int[students];
    float * avg = new float[students];
    float sum = 0;

    for(int i=0; i<students; i++) {
        cout << "\nEnter number of courses of Student " << i+1 << ": ";
        cin >> courses[i];
        marks[i] = new int[courses[i]];

        for(int j=0; j<courses[i]; j++) {
            cout << "Marks of course " << j+1 << ": ";
            cin >> marks[i][j];
            sum += marks[i][j];
        }
        avg[i] = sum / courses[i];
        sum = 0;
    }

    cout << endl;
    cout << " -------- Averages Marks -------- \n";
    for(int i=0; i<students; i++) {
        cout << "Student " << i+1 << ": ";
        for(int j=0; j<courses[i]; j++) {
            cout << marks[i][j] << " ";
        } 
        cout << " == " << avg[i] << endl;
    }

    for(int i=0; i<students; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] courses;
    delete[] avg;
}
