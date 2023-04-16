#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <time.h>

#define TIME 5000

using namespace std;

int main() {
	clock_t start, end;

	priority_queue<int> pq;
	vector<int> v;

	//priority_queue push speed
	start = clock();
	for (int i = 0; i < TIME; i++) {
		pq.push(i);
	}
	end = clock();
	cout << "PRIORITY QUEUE PUSH: " << (double)(end - start) << endl;

	//vector push speed
	start = clock();
	for (int i = 0; i < TIME; i++) {
		v.push_back(i);
		sort(v.begin(), v.end());
	}
	end = clock();
	cout << "VECTOR PUSH: " << (double)(end - start) << endl;

	//priority_queue pop speed
	start = clock();
	for (int i = 0; i < TIME; i++) {
		pq.pop();
	}
	end = clock();
	cout << "PRIORITY QUEUE POP: " << (double)(end - start) << endl;

	//vector pop speed
	start = clock();
	for (int i = 0; i < TIME; i++) {
		v.pop_back();
		sort(v.begin(), v.end());
	}
	
	end = clock();
	cout << "VECTOR POP: " << (double)(end - start) << endl;


}