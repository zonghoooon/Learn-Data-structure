#include <iostream>

using namespace std;


class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int getBalanceFactor(Node* node) {
    if (node == NULL) return 0;
    return node->left->height - node->right->height;
}

// 오른쪽 회전
Node* rightRotate(Node* node) {
    Node* lnode = node->left;
    Node* temp = lnode->right;
    lnode->right = node;
    node->left = temp;
    node->height = max(node->left->height,node->right->height) +1;
    lnode->height = max(lnode->left->height, lnode->right->height) + 1;
    return lnode;
}

// 왼쪽회전
Node* leftRotate(Node* node) {
    Node* lnode = node->right;
    Node* temp = lnode->left;
    lnode->left = node;
    node->right = temp;
    node->height = max(node->left->height, node->right->height) + 1;
    lnode->height = max(lnode->left->height, lnode->right->height) + 1;
    return lnode;
}


int main()
{
    std::cout << "Hello World!\n";
}

