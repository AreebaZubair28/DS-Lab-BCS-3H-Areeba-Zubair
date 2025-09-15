#include "iostream"
using namespace std;

void funcB(int n);

void printNumber(int n) {
    if(n==0) {
        return;
    }
    cout << n << endl;
    printNumber(n-1);
}

void funcA(int n) {
    if(n==0) {
        return;
    }
    cout << "A: " << n << endl;
    funcB(n-1);
}

void funcB(int n) {
    if(n==0) {
        return;
    }
    cout << "B: " << n << endl;
    funcA(n-1);
}

int main() {
    int n;
    cout << "Enter number: ";  cin>>n;

    cout << "------Printing Directly--------\n";
    printNumber(n);

    cout << "------Printing Indirectly--------\n";
    funcA(n);
}
