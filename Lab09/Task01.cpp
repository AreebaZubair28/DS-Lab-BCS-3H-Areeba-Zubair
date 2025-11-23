#include"iostream"
using namespace std;

class Student{
public:
    int rollNo, height;
    Student *left, *right;

    Student(int roll) : rollNo(roll), height(0), left(NULL), right(NULL) {}
};

int height(Student* root) {
    if(!root) return -1;
    return 1+max(height(root->left),height(root->right));
}

int BalanceFactor(Student* root) {
    if(!root) return 0;
    return height(root->left) - height(root->right);
}

Student* findMin(Student* root) {
    if(!root) return NULL;
    while(root->left) {
        root = root->left;
    }
    return root;
}

Student* R_Rotation(Student* x) {
    cout << "Rotation : Right\n";
    Student* y = x->left;
    Student* temp = y->right;

    y->right = x;
    x->left = temp;

    x->height = height(x);
    y->height = height(y);

    return y;
}

Student* L_Rotation(Student* x) {
    cout << "Rotation: Left\n";
    Student* y = x->right;
    Student* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = height(x);
    y->height = height(y);

    return y;
}

Student* insert(Student* root, int roll) {
    if(!root) {
        Student* newStudent = new Student(roll);
        return newStudent;
    }
    if(roll < root->rollNo) {
        root->left = insert(root->left, roll);
    }
    else if(roll > root->rollNo) {
        root->right = insert(root->right, roll);
    } else {
        return root;
    }

    root->height = height(root);
    int bf = BalanceFactor(root);
    cout << "Inserted: " << roll << " | Node: " << root->rollNo << " | Balance Factor: " << bf << endl;

    if(bf > 1 && roll < root->left->rollNo) {
        return R_Rotation(root);
    }
    if(bf < -1 && roll > root->right->rollNo) { 
        return L_Rotation(root);
    }
    if(bf > 1 && roll > root->left->rollNo) { 
        root->left = L_Rotation(root->left);
        return R_Rotation(root);
    }
    if(bf < -1 && roll < root->right->rollNo) { 
        root->right = R_Rotation(root->right);
        return L_Rotation(root);
    }

    return root;
}

Student* Delete(Student* root, int roll) {
    if(!root) {
        cout << "Empty List\n";
        return NULL;
    }
    if(roll < root->rollNo) {
        root->left = Delete(root->left, roll);
    }
    else if(roll > root->rollNo) {
        root->right = Delete(root->right, roll);
    } else {
        if(!root->left && !root->right) {
            delete root;
            return NULL;
        }
        else if(!root->left) {
            Student* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right) {
            Student* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Student* temp = findMin(root->right);
            root->rollNo = temp->rollNo;
            root->right = Delete(root->right, temp->rollNo);
        }
    }

    if (!root) return root;

    root->height = height(root);
    int balance = BalanceFactor(root);
    cout << "Deleted: " << roll << " | Node: " << root->rollNo << " | Balance Factor: " << balance << endl;

    if (balance > 1 && BalanceFactor(root->left) >= 0) {
        return R_Rotation(root);
    }

    if (balance > 1 && BalanceFactor(root->left) < 0) {
        root->left = L_Rotation(root->left);
        return R_Rotation(root);
    }

    if (balance < -1 && BalanceFactor(root->right) <= 0) {
        return L_Rotation(root);
    }

    if (balance < -1 && BalanceFactor(root->right) > 0) {
        root->right = R_Rotation(root->right);
        return L_Rotation(root);
    }
    return root;
}

int main() {
    int arr[] = {596, 599, 661, 678, 684, 676};
    int size = sizeof(arr) / sizeof(arr[0]);
    Student* root = NULL;

    cout << "---- Insertion ----\n";
    for(int i=0; i<size; i++) {
        root = insert(root, arr[i]);
        cout << "Height of Tree: " << height(root); 
        cout << endl << endl;
    }

    cout << "\n----- DELETION PHASE -----\n";
    root = Delete(root, 661);
    cout << "Tree Height After Delete: " << height(root) << "\n\n";

    root = Delete(root, 676);
    cout << "Tree Height After Delete: " << height(root) << "\n\n";

    root = Delete(root, 684);
    cout << "Tree Height After Delete: " << height(root) << "\n\n";
}
