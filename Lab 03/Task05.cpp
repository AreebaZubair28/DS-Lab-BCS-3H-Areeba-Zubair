#include "iostream"
using namespace std;

class SNode{
    public:
    int data;
    SNode* next;

    SNode(int val) : data(val), next(NULL) {}
};

class DNode{
    public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int val = 0) : data(val), next(NULL), prev(NULL) {}
};

DNode* insertAfter(DNode * temp, int data) {
    DNode * newNode = new DNode(data);
    temp->next = newNode;
    newNode->prev = temp;

    return newNode;
}

DNode* convertToDLL(SNode * Shead) {
    DNode * newNode = new DNode(Shead->data);
    DNode * head = newNode;

    while(Shead->next != NULL) {
        Shead = Shead->next;
        newNode = insertAfter(newNode, Shead->data);
    }

    return head;
}

SNode* convertToCLL(SNode * Shead) {
    SNode * head = Shead;

    while (head->next != NULL) {
        head = head->next;
    }
    head->next = Shead;

    return head;
}

void printwithNext(SNode * head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << " -> ";
    }
    cout << endl;
}

void printwithNext(DNode * head) {   // overload for DLL
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << " -> ";
    }
    cout << endl;
}

void printwithPrev(DNode * temp) {
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while(temp != NULL) {
        cout << temp->data;
        temp = temp->prev;
        if(temp != NULL) cout << " -> ";
    }
    cout << endl;
}

void printCLL(SNode * last) {
    SNode* start = last;
    do {
        cout << last->data;
        last = last->next;
        if(start != last) cout << " -> ";
    }while (start != last);
    cout << endl;
}

int main() {
    SNode * Shead = new SNode(1);
    SNode * second = new SNode(3);
    SNode * third = new SNode(5);
    SNode * fourth = new SNode(7);

    Shead->next = second;
    second->next = third;
    third->next = fourth;

    cout << "\n--------- Singly List ---------\n";
    printwithNext(Shead);

    DNode * Dhead = convertToDLL(Shead);
    cout << "\n--------- Doubly List ---------\n";
    printwithNext(Dhead);
    printwithPrev(Dhead);

    SNode * Chead = convertToCLL(Shead);    // returns last pointer
    cout << "\n--------- Circular List ---------\n";
    printCLL(Chead);
}


