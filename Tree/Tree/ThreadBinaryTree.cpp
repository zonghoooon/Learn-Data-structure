#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool isTread;

    Node(int temp) {
        data = temp;
        left = NULL;
        right = NULL;
        isTread = false;
    }
    Node(int temp, bool t) {
        data = temp;
        left = NULL;
        right = NULL;
        isTread = t;
    }
};

Node* FindSuccesor(Node* node) {
    Node* temp = node->right;

    if (temp == NULL || node->isTread) {
        return temp;
    }
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}
void TBT(Node* node) {
    Node* temp = node;
    while (temp->left) { temp = temp->left; }

    do {
        cout << temp->data << " ";
        temp = FindSuccesor(temp);
    } while (temp);


}



int main() {
    Node* root = new Node(0);

    root->left = new Node(1);
    root->right = new Node(2);

    root->left->left = new Node(3, true);
    root->left->left->right = root->left;
    root->left->right = new Node(4,true);
    root->left->right->right = root;
    root->right->left = new Node(5, true);
    root->right->left->right = root->right;
    root->right->right = new Node(6);

    /*
    *    0
    *   1 2
    * 3 4 5 6
    */

    TBT(root);

}