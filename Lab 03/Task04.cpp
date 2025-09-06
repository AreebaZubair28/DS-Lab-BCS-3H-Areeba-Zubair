#include "iostream"
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void JosephusProblem(Node * last, int k, int n) {
    Node * head = last->next;
    Node * prev;
    int count = 0;
    while(count != n-1) {
        Node * temp;
        for(int i=1; i<k; i++) {
            prev = head;
            head = head->next;
        }
        prev->next = head->next;
        temp = head;
        head = head->next;
        cout << "Eliminated: " << temp->data << endl;
        delete temp;
        count++;
    }

    cout << "Position of survival: " << head->data;
}

void printCLL(Node * last) {
    Node* start = last;
    do {
        cout << last->data;
        last = last->next;
        if(start != last) cout << " -> ";
    }while (start != last);
    cout << endl;
}

int main() {
    Node * first = new Node(1);
    Node * last = first;
    for(int i=2; i<=7; i++) {
        last->next = new Node(i);
        last = last->next;
    }
    last->next = first;

    JosephusProblem(last,3,7);
}