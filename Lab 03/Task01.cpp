#include "iostream"
#include "string"
using namespace std;

class Node {
    public:
    int data;
    Node * next;

    Node() {
        next = NULL;
    }
};

Node* createNode(Node * temp) {     // replaces the head each time a node created
    Node * newNode = new Node;
    int val;
    cout << "Enter data value: ";  cin>>val;
    newNode->data = val;
    newNode->next = temp;

    return newNode;
}

string moveback(Node * head) {
    if(head == NULL) {
        return "";
    }
    return moveback(head->next) + to_string(head->data);
}

bool Palindrome(Node * head, Node * tail) {
    string forward;
    string backward;
    while(head != NULL) {
        forward += to_string(head->data);
        head = head->next;
    }

    backward = moveback(tail);

    return forward == backward;
}

int main() {
    Node * head = new Node;
    cout << "Enter data to start the list: "; cin>>head->data;

    int numOfNodes;
    int count;
    cout << "Enter Number of Nodes you wanna create: ";  cin>>numOfNodes;
    count = numOfNodes;

    while (count > 0) {
        head = createNode(head);  // head pointer moves to newNode
        count--;
    }

    bool pal = Palindrome(head, head);

    if(pal) { cout << "Palindrome\n"; }
    else { cout << "Not Palindrom\n"; }

}
