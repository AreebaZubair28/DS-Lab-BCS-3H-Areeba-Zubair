#include "iostream"
using namespace std;

int sumTail(int n, int total) {
    if(n==0) {
        return total;
    }
    return sumTail(n-1, total+n);
}

int sumTail(int n) {
    if(n==0) {
        return 0;
    }
    return n + sumTail(n-1);
}

int main() {
    int n;
    cout << "Enter number: ";  cin>>n;
    cout << "Sum of " << n << ": " << sumTail(n,0);
    cout << "\nSum of " << n << ": " << sumTail(n);
}
/*
1- Tail recursion is more efficient in terms of stack memory because it allows optimization where the
 compiler reuses the same stack frame.
2- Non-tail recursion uses more stack space because each call must be retained until the previous calls
 finish their computations.
*/
