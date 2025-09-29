#include "iostream"
using namespace std;

#define MAX 5

class Stack{
    int top;

public:
   int array[MAX];

   Stack() : top(-1) {}

   bool push(int x) {
    if(top >= (MAX -1)) {
        cout << "Stack overflow\n";
        return false;
    } else {
        array[++top] = x;
        cout << x << " puched into stack\n";
        return true;
    }
   }

   int pop() {
    if(top < 0) {
        cout << "Stack is underflow\n";
        return 0;
    }else {
        int x = array[top--];
        return x;
    }
   }

   int peek() {
    if(top < 0) {
        cout << "Stack is empty\n";
        return -1;
    }else {
        int x = array[top];
        return x;
    }
   }

   void display() {
    if(top < 0) {
        cout << "\nDisplaying Stack Content\n";
        cout << "Stack is empty\n";
    } else {
        cout << "\nDisplaying Stack Content\n";
        for(int i=0 ; i<=top; i++) {
            cout << array[i] << endl;
        }
    }
   }
};

int main() {
    Stack s;
    s.push(6);
    s.push(3);
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(5);
    s.display();
    cout << endl;
    cout << s.pop() << " poped out of stack\n"; 
    cout << s.pop() << " poped out of stack\n"; 
    cout << s.pop() << " poped out of stack\n";
    cout << endl;
    cout << s.peek() << " peeked out of stack\n"; 
    cout << endl;
    cout << s.pop() << " poped out of stack\n"; 
    cout << s.pop() << " poped out of stack\n"; 
    cout << endl;
    s.display();
}
