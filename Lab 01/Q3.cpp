# include "iostream"
using namespace std;

class Box{
    int * num;

public:
    Box(int n) : num(new int(n)) {}

    void setNum(int n) {
        *num = n;
    }

    Box (const Box& other) {        // deep copy
        num = new int(*other.num);
    }

    Box& operator=(const Box& other) {    // assignment operator
        if(this == &other) {
            return *this;
        }

        delete num;
        num = new int(*other.num);

         return *this;
    }

    void display() {
        cout << *num << endl;
    }

    ~Box() {                        // destructor
        delete num;
    }
};

class Shallow {
    int * num;

public:
    Shallow(int n) {
        num = new int(n);
    }

    void setNum(int n) {
        *num = n;
    }

    void display() {
        cout << *num << endl;
    }

    ~Shallow() {
        delete num;
    }
};

int main() {
    cout << "\n-------- Shallow Copy Demonstration --------"<<endl;
    Shallow s1(2);
    Shallow s2 = s1;
    cout<<"Values before modification:\n";
    s1.display();
    s2.display();

    s2.setNum(10);

    cout<<"Values after modification:\n";
    s1.display();
    s2.display();


    cout << "\n\n-------- Deep Copy Demonstration --------"<<endl;
    Box b1(2);
    Box b2 = b1;
    cout<<"Values before modification:\n";
    b1.display();
    b2.display();

    b2.setNum(10);

    cout<<"Values after modification:\n";
    b1.display();
    b2.display();

    cout << "\n\n-------- Copy Assignment Operator Demonstration --------"<<endl;
    cout<<"Values before modification:\n";
    b1.display();
    b2.display();

    b1.setNum(90);

    b2 = b1;
    cout<<"Values after modification:\n";
    b1.display();
    b2.display();
}
