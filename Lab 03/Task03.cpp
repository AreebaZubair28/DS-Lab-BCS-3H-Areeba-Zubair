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

Node* createNode(Node * temp, int data) {     // replaces the head each time a node created
    Node * newNode = new Node(data);
    newNode->next = temp;

    return newNode;
}

Node * reverseInGroup(Node * head) {
    if(!head) { return NULL; }

    Node * next = NULL;
    Node * curr = head;
    Node * prev = NULL;

    int count = 1;

    while(curr != NULL && count <= 3) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL) {
        head->next = reverseInGroup(next);
    }

    return prev;

}

void printList(Node * temp) {
    while(temp != NULL) {
        cout << temp->data;
        temp = temp->next;
        if(temp != NULL) { cout << " -> "; }
    }
    cout << endl;
}

int main() {
    int numOfNodes;
    int count;
    int data;
    cout << "Enter Number of Nodes you wanna create: ";  cin>>numOfNodes;
    count = numOfNodes - 1;

    cout << "Enter data for the last node: "; cin>>data;
    Node * head = new Node(data);
    int i= count;

    while (count > 0) {
        cout << "Enter data for " << i << " node: "; cin>>data;
        head = createNode(head, data);  // head pointer moves to newNode
        count--;
        i--;
    }

    cout << "\n------- Original List -------\n";
    printList(head);

    head = reverseInGroup(head);
    cout << "\n------- Reversed List in Group of 3 -------\n";
    printList(head);
}