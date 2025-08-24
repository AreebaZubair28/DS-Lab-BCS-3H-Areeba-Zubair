# include "iostream"
using namespace std;

class BankAccount{
    float balance;

public:
    BankAccount() {  // default constructor
        balance = 0.0;
        cout << "Default Constructor called!" << endl;
    }

    BankAccount(float b) {  // parametrize constructor
        balance = b;
        cout << "Parametrize Constructor called!" << endl;
    }

    BankAccount(const BankAccount& other) {  // deep copy constructor
        balance = other.balance;
        cout << "Deep Copy Constructor called!" << endl;
    }

    void withdraw(float amt) {
        balance -= 200;
    }

    void print() {
        cout << "Balance: $" << balance << endl <<endl;
    }
};

int main() {
    BankAccount acc1;
    cout << "Acc 1" <<endl;
    acc1.print();

    BankAccount acc2(1000);
    cout << "Acc 2" <<endl;
    acc2.print();

    BankAccount acc3 = acc2;
    cout << "Acc 3" <<endl;
    acc3.print();
    acc3.withdraw(200);
    cout << "Acc 2" <<endl;
    acc2.print();
    cout << "Acc 3" <<endl;
    acc3.print();
}
