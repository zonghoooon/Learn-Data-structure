#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int temp) {
        key = temp;
        left = NULL;
        right = NULL;
    }
};


Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* node = new Node(val);
        return node;
    }
    if (val < root->key) {
        root->left = insert(root->left, val);
    }
    else if (val > root->key) {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* Delete(Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (val < root->key) {
        root->left = Delete(root->left, val);
    }
    else if (val > root->key) {
        root->right = Delete(root->right, val);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->key = temp->key;
        root->right = Delete(root->right, temp->key);
    }
    return root;
}

void In(Node* root) {
    if (root == NULL) {
        return;
    }
    In(root->left);
    cout << root->key << " ";
    In(root->right);
}


int main() {

    Node* root = NULL;

    int n;
    cout << "트리의 크기: ";
    cin >> n;

    cout << "숫자 배열: ";

    int temp;
    cin >> temp;
    root = insert(root, temp);

    for (int i = 1; i < n; i++) {
        cin >> temp;
        root = insert(root, temp);
    }


    cout << "정렬된 숫자: ";
    In(root);
    cout << endl;

    return 0;
}
