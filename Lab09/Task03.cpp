#include <iostream>
using namespace std;

class Node {
public:
    int score, height;
    Node *left, *right;

    Node(int s) : score(s), height(0), left(NULL), right(NULL) {}
};

int height(Node* root) {
    if (!root) return -1;
    return 1 + max(height(root->left), height(root->right));
}

int balanceFactor(Node* root) {
    if (!root) return 0;
    return height(root->left) - height(root->right);
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root->right) root = root->right;
    return root;
}

Node* rightRotate(Node* x) {
    cout << "Rotation Applied: Right Rotation (LL)\n";
    Node* y = x->left;
    Node* temp = y->right;

    y->right = x;
    x->left = temp;

    x->height = height(x);
    y->height = height(y);
    return y;
}

Node* leftRotate(Node* x) {
    cout << "Rotation Applied: Left Rotation (RR)\n";
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = height(x);
    y->height = height(y);
    return y;
}

Node* insert(Node* root, int s) {
    if (!root) {
        cout << "Inserted new patient with score = " << s << endl;
        return new Node(s);
    }

    if (s < root->score)
        root->left = insert(root->left, s);
    else if (s > root->score)
        root->right = insert(root->right, s);
    else {
        cout << "Duplicate score not allowed.\n";
        return root;
    }

    root->height = height(root);
    int bf = balanceFactor(root);

    if (bf > 1 && s < root->left->score)
        return rightRotate(root);

    if (bf < -1 && s > root->right->score)
        return leftRotate(root);

    if (bf > 1 && s > root->left->score) {
        cout << "Rotation Applied: Left-Right (LR)\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && s < root->right->score) {
        cout << "Rotation Applied: Right-Left (RL)\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->score)
        root->left = deleteNode(root->left, key);
    else if (key > root->score)
        root->right = deleteNode(root->right, key);

    else { 
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->score = temp->score;
        root->right = deleteNode(root->right, temp->score);
    }

    if (!root) return root;

    root->height = height(root);
    int bf = balanceFactor(root);

    if (bf > 1 && balanceFactor(root->left) >= 0) {
        cout << "Rotation Applied (Delete): LL\n";
        return rightRotate(root);
    }

    if (bf > 1 && balanceFactor(root->left) < 0) {
        cout << "Rotation Applied (Delete): LR\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && balanceFactor(root->right) <= 0) {
        cout << "Rotation Applied (Delete): RR\n";
        return leftRotate(root);
    }

    if (bf < -1 && balanceFactor(root->right) > 0) {
        cout << "Rotation Applied (Delete): RL\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printHighest(Node* root) {
    if (!root) return;
    Node* highest = findMax(root);
    cout << "Highest severity patient score = " << highest->score << endl;
}

int main() {
    Node* root = NULL;
    int choice, score;

    while (true) {
        cout << "\n--- Hospital Severity AVL System ---\n";
        cout << "1. Insert new patient\n";
        cout << "2. Discharge patient (Delete score)\n";
        cout << "3. Show highest severity patient\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter severity score: ";
            cin >> score;
            root = insert(root, score);
            cout << "Tree height after insertion = " << height(root) << endl;
        }
        else if (choice == 2) {
            cout << "Enter severity score to delete: ";
            cin >> score;
            root = deleteNode(root, score);
            cout << "Tree height after deletion = " << height(root) << endl;
        }
        else if (choice == 3) {
            printHighest(root);
        }
        else {
            break;
        }
    }

    return 0;
}
