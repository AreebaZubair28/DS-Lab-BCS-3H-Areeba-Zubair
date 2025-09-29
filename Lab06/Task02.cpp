# include "iostream"
using namespace std;

class Node {
    public:
    string data;
    Node* next;

    Node(string x) : data(x), next(NULL) {}
};

void push(Node*& top, string data) {
    Node* temp = new Node(data);
    temp->next = top;
    top = temp;
    cout << top->data << " visited\n";
}

void pop(Node*& top) {
    if(!top) {
        cout << "No previous page(Empty History)\n";
        return;
    } else {
        Node* temp = top;
        top = top->next;
        cout << "Going back from " << temp->data << endl; 
        delete temp;
    }
}

void peek(Node* top) {
    if(!top) {
        cout << "No page open\n";
        return;
    } else {
        cout << "Currently on " << top->data << endl; 
    }
}

void print(Node* top) {
    cout << "Browser History\n";
    while(top != NULL) {
        cout << top->data;
        if(top->next != NULL) {
            cout << "->";
        }
        top = top->next;
    }
    cout << endl;
}

int main() {
    Node * top = NULL;
    push(top, "www.google.com");
    push(top, "www.facebook.com");
    push(top, "www.youtube.com");
    push(top, "www.github.com");

    cout << endl;
    peek(top);
    cout << endl;

    pop(top);
    cout << endl;
    peek(top);
    cout << endl;

    print(top);
}
