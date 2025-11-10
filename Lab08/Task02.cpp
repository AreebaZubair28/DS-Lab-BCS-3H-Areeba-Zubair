#include "iostream"
#include "queue"
using namespace std;

struct Node{
    string Songname;
    int playCount;
    Node *left, *right;
    
    Node(string name, int count) : Songname(name), playCount(count), left(NULL), right(NULL) {}
};

Node* insert(Node* root, string song, int count) {
    if(!root) {
        return new Node(song, count);
    }

    if(count < root->playCount) {
        root->left = insert(root->left, song, count);
    }
    else if(count > root->playCount) {
        root->right = insert(root->right, song, count);
    }
    return root;
}

Node* search(Node* root, int count) {
    if(root->playCount == count || !root) {
        cout << "Found -- " << root->Songname<< endl;
        return root;
    }
    else if(count < root->playCount) {
        return search(root->left, count);
    }
    return search(root->right, count);
}

void Inorder(Node* root) {
    if(!root) return;
    Inorder(root->left);
    cout << root->Songname << ", ";
    Inorder(root->right);
}

void Postorder(Node* root) {
    if(!root) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->Songname << ", ";
}

Node* findMin(Node* root) {
    if(!root) {
        cout << "Tree is empty\n";
        return NULL;
    }
    while(root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int count) {
    if(!root) {
        cout << "Tree is empty\n";
        return NULL;
    }

    if(count < root->playCount) {
        root->left = deleteNode(root->left, count);
    }
    else if(count > root->playCount) {
        root->right = deleteNode(root->right, count);
    }
    else {
        // if no child
        if(!root->left && !root->right) {
            delete root;
            return NULL;
        }
        else if(!root->left) {  // only right child
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if(!root->right) {  // only left child
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {   // both childs
            Node* temp = findMin(root->right);
            root->Songname = temp->Songname;
            root->right = deleteNode(root->right, temp->playCount);
        }  
    }
    return root;
}

int main() {
    Node* root = NULL;

    // Insert songs (playCount acts as BST key)
    root = insert(root, "Shape of You", 150);
    root = insert(root, "Perfect", 120);
    root = insert(root, "Blinding Lights", 200);
    root = insert(root, "Levitating", 180);
    root = insert(root, "Peaches", 90);

    cout << "\nInorder: ";
    Inorder(root);
    cout << endl;

    cout << "\nPostorder: ";
    Postorder(root);
    cout << endl;

    cout << "\nSearching for song with play count 180...\n";
    search(root, 180);

    cout << "\nDeleting song with play count 120 (Perfect)...\n";
    root = deleteNode(root, 120);

    cout << "\nUpdated Inorder after deletion: ";
    Inorder(root);
    cout << endl;

    return 0;
}
