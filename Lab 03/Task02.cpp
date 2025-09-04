#include "iostream"
using namespace std;

class Node {
    public:
    int data;
    Node * next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void traverse(Node * head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) { cout << " -> "; }
    }
    cout << endl;
}

Node * merge(Node * A, Node * B) {
    if(!A) { return B; }
    if(!B) { return A; }

    Node * head = NULL;  
    Node * tail = NULL;

    if(A->data <= B->data) {
        head = A;
        A = A->next;
    } else {
        head = B;
        B = B->next;    
    }
    tail = head;

    while(A && B) {
        if(A->data <= B->data) {
            tail->next = A;
            A = A->next;
        } else {
            tail->next = B;
            B = B->next;    
        }
        tail = tail->next;
    }

    if(!A) { tail->next = B; }
    if(!B) { tail->next = A; }

    return head;
}

int main() {
    Node * A = new Node(1);
    A->next = new Node(3);
    A->next->next = new Node(5);

    Node * B = new Node(2);
    B->next = new Node(4);
    B->next->next = new Node(6);

    cout << "\n------ List A ------\n";
    traverse(A);
    cout << "\n------ List B ------\n";
    traverse(B);

    Node * mergedList = merge(A, B);
    
    cout << "\n------ Sorted List ------\n";
    traverse(mergedList);
    cout << endl;
}