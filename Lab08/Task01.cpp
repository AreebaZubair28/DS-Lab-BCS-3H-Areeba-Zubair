#include "iostream"
#include "queue"
using namespace std;

struct Node{
    string name;
    Node *left, *right;
    
    Node(string val) : name(val), left(NULL), right(NULL) {}
};

int height(Node* root) {
    if (!root) return -1;
    return 1+max(height(root->left), height(root->right));
}

void leaf(Node* root) {
    if(!root) {
        return;
    }
    if(!root->left && !root->right) {
        cout << root->name << endl;
        return;
    }
    leaf(root->left);
    leaf(root->right); 
}

void Levels(Node* root) {
    if (!root) return;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        Node* curr = q.front().first;
        int level = q.front().second;
        q.pop();

        cout << curr->name << " is at level " << level << endl;

        if (curr->left) q.push({curr->left, level + 1});
        if (curr->right) q.push({curr->right, level + 1});
    }
}

int main(){
    Node* root = new Node("Areeba");
    root->left = new Node("Azra");
    root->left->left = new Node("Zareen");
    root->left->right = new Node("Yaqoob");
    
    root->right = new Node("Zubair");
    root->right->right = new Node("Abdullah");
    root->right->left = new Node("Rehmat");

    cout << "Youngest person: " << root->name << endl;

    cout << "\nLeaf Node: "<<endl;
    leaf(root);
    cout << "\nHeight of Tree: " << height(root) << endl;
    cout << "\nLevels: " << endl;
    Levels(root);
    cout << endl;
}
