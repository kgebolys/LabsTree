#include <iostream>
using namespace std;

struct drzewoBST {
    drzewoBST* up;
    drzewoBST* left;
    drzewoBST* right;
    int val;
};

void Dodaj(drzewoBST*& root, int x) {
    if (root == NULL) {
        drzewoBST* w = new drzewoBST;
        w->left = NULL;
        w->right = NULL;
        w->val = x;
        root = w;
    }
    else {
        if (x > root->val) {
            Dodaj(root->right, x);
        } else if
                (x < root->val) Dodaj(root->left, x);      
    }
}

drzewoBST* szukaj(drzewoBST*& root, int x) {
    if (root != NULL) {
        drzewoBST* T = root;
        if (T->val == x) 
            return T;
        else {
            if (x > T->val) szukaj(T->right, x);
            else szukaj(T->left, x);
        }
    }
    else return NULL;
}

void skasujdrzewo(drzewoBST*& root,float x) {
        if (root->val > x) {
            delete root;
            root = NULL;
        }
    else {
        if (root->left != NULL) {
            skasujdrzewo(root->left, x);
        }
        if (root->right != NULL) {
            skasujdrzewo(root->right, x);
        }
    }
}

drzewoBST* znajdzMin(drzewoBST*& root) {
    drzewoBST* T = root;
    while (T->left) {
        T = T->left;
    }
    return T;
}
drzewoBST* znajdzMax(drzewoBST*& root) {
    drzewoBST* T = root;
    while (T->right) {
        T = T->right;
    }
    return T;
}

void skasujwiekszeodx(drzewoBST*& root, float x) {
    if (root->val > x) {
        root = root->left;
        delete root;
        root = NULL;
    }
    else {
        if (root->left != NULL) {
            skasujwiekszeodx(root->left, x);
        }
        if (root->right != NULL) {
            skasujwiekszeodx(root->right, x);
        }
    }
}
void usunwiekszeodsredniej(drzewoBST*& root) {
    if (root != NULL) {
        int x = znajdzMin(root)->val;
        int y = znajdzMax(root)->val;
        float srednia = (x + y) / 2;
        skasujdrzewo(root, srednia);
    }
}

void inorder(drzewoBST*& root) {
    if (root == NULL) {
        return;
    }else{
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
    }
}

void preorder(drzewoBST*& root) {
    if (root != NULL) {
        cout << root->val << endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(drzewoBST*& root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << endl;
    }
}

int main() {
    drzewoBST* root = NULL;
    Dodaj(root, 100);
    Dodaj(root, 30);
    Dodaj(root, 45);
    Dodaj(root, 60);
    Dodaj(root, 120);
    Dodaj(root, 111);
    Dodaj(root, 105);
    cout << szukaj(root, 11) << endl;
    //deleteLeaves(root);
    //inorder(root);
    //preorder(root);
    inorder(root);
    //cout << searchMin(root)->val << endl;
    //cout << searchMax(root)->val << endl;
    cout << "test" << endl;
    skasujdrzewo(root,101);
    inorder(root);
    return 0;
    system("pause");
}