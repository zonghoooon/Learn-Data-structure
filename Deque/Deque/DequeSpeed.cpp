#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <time.h>

#define TIME 500000

using namespace std;

int main() {

	clock_t start, end;

	deque<int> dq;
	vector<int> v;
	list<int> l;

	start = clock();
	for (int i = 0; i < TIME; i++) {
		dq.push_back(i);
		dq.push_front(i);
	}
	end = clock();
	cout << "DEQUE PUSH: " << (double)(end - start) << endl;

	start = clock();
	for (int i = 0; i < TIME; i++) {
		v.push_back(i);
		v.insert(v.begin(),i );
	}
	end = clock();
	cout << "VECTOR PUSH: " << (double)(end - start) << endl;

	start = clock();
	for (int i = 0; i < TIME; i++) {
		l.push_back(i);
		l.push_front(i);
	}
	end = clock();
	cout << "LIST PUSH: " << (double)(end - start) << endl;

	cout << endl;

	start = clock();
	for (int i = 0; i < TIME; i++) {
		dq.pop_back();
		dq.pop_front();
	}
	end = clock();
	cout << "DEQUE POP: " << (double)(end - start) << endl;

	start = clock();
	for (int i = 0; i < TIME; i++) {
		v.pop_back();
		v.erase(v.begin());
	}
	end = clock();
	cout << "VECTOR POP: " << (double)(end - start) << endl;

	start = clock();
	for (int i = 0; i < TIME; i++) {
		l.pop_back();
		l.pop_front();
	}
	end = clock();
	cout << "LIST POP: " << (double)(end - start) << endl;


	cout << endl;

	start = clock();
	for (int i = 0; i < TIME; i++) {
		dq.insert(dq.begin(), i);
	}
	end = clock();	
	cout << "DEQUE INSERT: " << (double)(end - start) << endl;

	start = clock();
	for (int i = 0; i < TIME; i++) {
		l.insert(l.begin(), i);
	}
	end = clock();
	cout << "LIST INSERT: " << (double)(end - start) << endl;



}