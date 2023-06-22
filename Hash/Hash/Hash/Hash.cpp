#include <iostream>

#define TABLE_SIZE	10

struct Node {
	int key;
	int value;
	Node* next;
	Node(int a, int b) {
		key = a;
		value = b;
		next = NULL;
	}
};

Node* hash_table[TABLE_SIZE];

int HashFunction(int key) {
	return key & TABLE_SIZE;
}

void Add(int key, int value) {
	Node* newNode = new Node(key, value);

	int index = HashFunction(key);
	if (hash_table[index] == NULL) {
		hash_table[index] = newNode;
	}
	else {
		newNode->next = hash_table[index];
		hash_table[index] = newNode;
	}
	return;
}

int main() {

}