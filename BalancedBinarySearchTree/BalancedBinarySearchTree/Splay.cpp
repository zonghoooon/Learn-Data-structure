using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

void splay(Node* x) {
    while (x->parent) {
        if (!x->parent->parent) {
            if (x->parent->left == x) right_rotate(x->parent);
            else left_rotate(x->parent);
        }
        else if (x->parent->left == x && x->parent->parent->left == x->parent) {
            right_rotate(x->parent->parent);
            right_rotate(x->parent);
        }
        else if (x->parent->right == x && x->parent->parent->right == x->parent) {
            left_rotate(x->parent->parent);
            left_rotate(x->parent);
        }
        else if (x->parent->left == x && x->parent->parent->right == x->parent) {
            right_rotate(x->parent);
            left_rotate(x->parent);
        }
        else {
            left_rotate(x->parent);
            right_rotate(x->parent);
        }
    }
}
