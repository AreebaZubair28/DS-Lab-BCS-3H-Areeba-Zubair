#include "iostream"
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = NULL;
        child = NULL;
    }
};

void flatten(Node * head) {
    Node * next;
    Node * child;

    while(head != NULL) {
        if(head->child != NULL) {
            next = head->next;
            head->next = head->child;
            child = head->child;
            while(child->next != NULL) {
                child = child->next;
            }
            child->next = next;
        }
        head = head->next;
    }
}

void traverse(Node* temp) {
    while(temp != NULL) {
        cout << temp->data;
        temp = temp->next;
        if(temp != NULL) { cout << " -> "; }
    }
    cout << endl;
}

void printChildL(Node * temp) {
    cout << temp->data << " -> ";
    temp = temp->child;
    while(temp != NULL) {
        cout << temp->data;
        temp = temp->next;
        if(temp != NULL) { cout << " -> "; }
    }
    cout << endl;
}


int main() {
    Node * first = new Node(1);
    Node * second = new Node(2);
    Node * third = new Node(3);

    first->next = second;
    second->next = third;
    second->child = new Node(4);
    second->child->next = new Node(5);

    traverse(first);
    printChildL(second);
    flatten(first);
    traverse(first);
}