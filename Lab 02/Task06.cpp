#include"iostream"
using namespace std;

class SafePointers{
    int * ptr;

public:
    SafePointers() {
        ptr = new int(0);
    }

    void setValue(int marks) { *ptr = marks; }

    int getValue() { return *ptr; }

    void release() {
        if(ptr != nullptr) {
            delete ptr;
            ptr = nullptr;
        }
    }

    ~SafePointers() {
        release();
    }
};

int main() {
    SafePointers marks[5];
    int mark;

    for(int i=0; i<5; i++) {
        cout<< "Enter marks of student " << i+1 << ": ";   cin >> mark;
        marks[i].setValue(mark);
    }

    for(int i=0; i<5; i++) {
        cout<< "\nMarks of student " << i+1 << ": ";  
        cout << marks[i].getValue();
    }
}
