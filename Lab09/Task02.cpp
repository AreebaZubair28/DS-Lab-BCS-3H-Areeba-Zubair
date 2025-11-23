#include"iostream"
using namespace std;

class Price{
public:
    int price, height;
    Price *left, *right;

    Price(int p) : price(p), height(0), left(NULL), right(NULL) {}
};

int height(Price* root) {
    if(!root) return -1;
    return 1+max(height(root->left),height(root->right));
}

int BalanceFactor(Price* root) {
    if(!root) return 0;
    return height(root->left) - height(root->right);
}

Price* findMin(Price* root) {
    if(!root) return NULL;
    while(root->left) {
        root = root->left;
    }
    return root;
}

Price* R_Rotation(Price* x) {
    Price* y = x->left;
    Price* temp = y->right;

    y->right = x;
    x->left = temp;

    x->height = height(x);
    y->height = height(y);

    return y;
}

Price* L_Rotation(Price* x) {
    Price* y = x->right;
    Price* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = height(x);
    y->height = height(y);

    return y;
}

Price* insert(Price* root, int p) {
    if(!root) {
        Price* newStudent = new Price(p);
        return newStudent;
    }
    if(p < root->price) {
        root->left = insert(root->left, p);
    }
    else if(p > root->price) {
        root->right = insert(root->right, p);
    } else {
        return root;
    }

    root->height = height(root);
    int bf = BalanceFactor(root);

    if(bf > 1 && p < root->left->price) {
        return R_Rotation(root);
    }
    if(bf < -1 && p > root->right->price) { 
        return L_Rotation(root);
    }
    if(bf > 1 && p > root->left->price) { 
        root->left = L_Rotation(root->left);
        return R_Rotation(root);
    }
    if(bf < -1 && p < root->right->price) { 
        root->right = R_Rotation(root->right);
        return L_Rotation(root);
    }

    return root;
}

void rangeQuery(Price* root, int X, int Y) {
    if (!root) return;

    if (root->price > X)
        rangeQuery(root->left, X, Y);

    if (root->price >= X && root->price <= Y)
        cout << root->price << " ";

    if (root->price < Y)
        rangeQuery(root->right, X, Y);
}


void inOrder(Price* root) {
    if(!root) return;
    inOrder(root->left);
    cout << root->price << " ";
    inOrder(root->right);
}

int main() {
    int arr[] = {120,330,560,780,500,450,670,900};
    int size = sizeof(arr) / sizeof(arr[0]);
    Price* root = NULL;

    for(int i=0; i<size; i++) {
        root = insert(root, arr[i]);
    }

    int x, y;
    cout << "Enter starting range: "; cin>>x;
    cout << "Enter ending range: "; cin>>y;

    rangeQuery(root, x, y);
}
