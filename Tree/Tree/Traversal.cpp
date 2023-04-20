#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

    Node(int temp) {
        data = temp;
        left = NULL;
        right = NULL;
    }
};

void Pre(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    Pre(node->left);
    Pre(node->right);
}

void In(Node* node) {
    if (node == NULL) return;
    In(node->left);
    cout << node->data << " ";
    In(node->right);
}

void Post(Node* node) {
    if (node == NULL) return;
    Post(node->left);
    Post(node->right);
    cout << node->data << " ";
}

void Level(Node* node) {
    
    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp != NULL) {
            cout << temp->data << " ";
            q.push(temp->left);
            q.push(temp->right);
        }
    }
}



int main() {
    Node* root = new Node(0);

    root->left = new Node(1);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    /*
    *    0
    *   1 2
    * 3 4 5 6
    */

    Pre(root); cout << endl;
    In(root); cout << endl;
    Post(root); cout << endl;
    Level(root);
        
}