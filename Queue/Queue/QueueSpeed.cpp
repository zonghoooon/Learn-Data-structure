#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <time.h>

#define TIME 1000000

using namespace std;

int main() {
	clock_t start, end;

	queue<int> que;
	deque<int> deq;
	vector<int> vec;
	list<int> lis;

	//queue push
	start = clock();
	for (int i = 0; i < TIME; i++) {
		que.push(i);
	}
	end = clock();
	cout << "QUEUE push: " << (double)(end - start) << endl;

	//deque push
	start = clock();
	for (int i = 0; i < TIME; i++) {
		deq.push_back(i);
	}
	end = clock();
	cout << "DEQUE push: " << (double)(end - start) << endl;

	//vector push
	start = clock();
	for (int i = 0; i < TIME; i++) {
		vec.push_back(i);
	}
	end = clock();
	cout << "VECTOR push: " << (double)(end - start) << endl;

	//list push
	start = clock();
	for (int i = 0; i < TIME; i++) {
		lis.push_back(i);
	}
	end = clock();
	cout << "LIST push: " << (double)(end - start) << endl;

	cout << endl;

	//queue pop
	start = clock();
	for (int i = 0; i < TIME; i++) {
		que.pop();
	}
	end = clock();
	cout << "QUEUE pop: " << (double)(end - start) << endl;

	//deque pop
	start = clock();
	for (int i = 0; i < TIME; i++) {
		deq.pop_front();
	}
	end = clock();
	cout << "DEQUE pop: " << (double)(end - start) << endl;

	//vector pop
	start = clock();
	for (int i = 0; i < TIME; i++) {
		vec.erase(vec.begin());
	}
	end = clock();
	cout << "VECTOR pop: " << (double)(end - start) << endl;

	//list pop
	start = clock();
	for (int i = 0; i < TIME; i++) {
		lis.pop_front();
	}
	end = clock();
	cout << "LIST pop: " << (double)(end - start) << endl;
}