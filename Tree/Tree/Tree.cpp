#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string temp) {
        data = temp;
        left = NULL;
        right = NULL;
    }
};

void Print(Node* node) {
    queue<Node*> q;
    vector<string> v;
    vector<int> lv;
    q.push(node);
    v.push_back(node->data);
    v.push_back(" ");
    lv.push_back(1);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            if (temp->left) { q.push(temp->left); v.push_back(temp->left->data); }
            if (temp->right) { q.push(temp->right); v.push_back(temp->right->data);
            }
        }
        v.push_back(" ");
        lv.push_back(q.size());
    }

    int temp = v.size()-1;
    int t = 0;
    for (temp; temp >= 0;temp--) {
        if (v[temp] == " ") {
            cout << endl;
            for (int i = 0; i < 4-lv[lv.size() - 1 - t]; i++) {
                cout << " ";
            }
            t++;
        }
        else {
            cout <<" " << v[temp] <<" ";
        }

    }
}

int main()
{
    Node* root = new Node("||");

    root->left = new Node("#");
    root->right = new Node("#");

    root->left->left = new Node("#");
    root->left->right = new Node("#");
    root->right->left = new Node("#");
    root->right->right = new Node("#");
    root->left->left->left = new Node("#");
    root->left->right->left = new Node("#");
    root->right->left->left = new Node("#");
    root->right->right->left = new Node("#");
    root->right->left->left->left = new Node("#");
    root->right->right->left->left = new Node("#");

    Print(root);

}