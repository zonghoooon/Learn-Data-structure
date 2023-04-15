#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

template <typename T>
class circular_queue {
public:
	T arr[SIZE];
	int front = 0;
	int rear = 0;

	T get() {return arr[front];}
	bool empty() { return (front == rear); }
	bool full() { return ((rear + 1) % SIZE == front); }
	bool size() { return abs(front - rear); }
	void push(T element) {
		if (full()) return;
		else {
			arr[rear] = element;
			rear++;
			rear %= SIZE;
		}
	}
	void pop() {
		if (empty()) return;
		else {
			front++;
			front %= SIZE;
		}
	}
};
struct Person
{
	int num;
	string name;
};
int main() {
	circular_queue<Person> waitingList;

	//100개 push
	for (int i = 0; i < 100; i++) {
		waitingList.push(Person{ i + 1,"Person" + to_string(i+1)});
	}

	//전부 pop
	while (!waitingList.empty()) {
		Person temp = waitingList.get();
		waitingList.pop();
		cout << temp.num << " " << temp.name << endl;
	}

	//100개 push
	for (int i = 0; i < 100; i++) {
		waitingList.push(Person{ i + 1,"Person" + to_string(i + 1) });
	}

	//전부 pop
	while (!waitingList.empty()) {
		Person temp = waitingList.get();
		waitingList.pop();
		cout << temp.num << " " << temp.name << endl;
	}
}