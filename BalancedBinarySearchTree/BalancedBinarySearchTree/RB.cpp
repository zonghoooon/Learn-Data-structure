#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;
	int color;
    Node* sibling(Node* node) {
        if (node->parent->left == node) return node->parent->right;
        else node->parent->left;
    }
};
enum Color {
    BLACK,
    RED
};
void insert1(Node* node)
{
    //조부모 노드
    Node* g = node->parent->parent;

    node->parent->color = BLACK;
    g->color = RED;
    if (node == node->parent->left)
        rotate_right(g);
    else
        rotate_left(g);
}

void insert2(Node* node)
{
    Node temp = Node();
    Node* u = temp.sibling(node), * g;

    if ((u != NULL) && (u->color == RED)) {
        node->parent->color = BLACK;
        u->color = BLACK;
        g = node-> parent->parent;
        g->color = RED;
    }
}
