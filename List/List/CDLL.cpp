#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int num, Node* l, Node* r) {
		data = num;
		left = l;
		right = r;
	}
};

struct CDLL {
	Node* head;

	CDLL() { head = NULL; }
	bool empty() {return (head==NULL);}
	void push_back(int temp) {
		Node* node = new Node(temp, NULL, NULL);
		if (empty()) {
			head = node;
			node->right = node;
			node->left = node;
		}
		else {
			node->right = head;
			node->left = head->left;
			head->left->right = node;
			head->left = node;
		}
	}
	void pop_back() {
		if (empty()) {
			return;
		}
		else {
			head->left->left->right = head;
			head->left = head->left->left;
		}
	}
	Node* back() {
		if (head->left == NULL) return head;
		else return head->left;
	}

};

int main() {

	CDLL a;

	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	for (int i = 0; i < 10; i++) {
		Node* temp = a.back();
		a.pop_back();
		cout << temp->data << endl;
	}
}