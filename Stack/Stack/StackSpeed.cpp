#include <iostream>
#include <time.h>
#include <stack>
#include <deque>
#include <vector>

#define TIME 10000000

using namespace std;

int main()
{
    vector<int> vec;
    stack<int> sta;
    deque<int> deq;
    clock_t start, end;

    //vector push 속도
    start = clock();
    for (int i = 0; i < TIME; i++) {
        vec.push_back(i);
    }
    end = clock();
    cout << "vector_push: " << (double)(end - start) << "\n";

    //stack push 속도
    start = clock();
    for (int i = 0; i < TIME; i++) {
        sta.push(i);
    }
    end = clock();
    cout << "stack_push: " << (double)(end - start) << "\n";

    //deque push 속도
    start = clock();
    for (int i = 0; i < TIME; i++) {
        deq.push_back(i);
    }
    end = clock();
    cout << "deque_push: " << (double)(end - start) << "\n";

    //vector pop 속도
    start = clock();
    for (int i = 0; i < TIME; i++) {
        vec.pop_back();
    }
    end = clock();
    cout << "vector_pop: " << (double)(end - start) << "\n";

    //stack pop 속도
    start = clock();
    for (int i = 0; i < TIME; i++) {
        sta.pop();
    }
    end = clock();
    cout << "stack_pop: " << (double)(end - start) << "\n";

    //deque pop 속도
    start = clock();
    for (int i = 0; i < TIME; i++) {
        deq.pop_back();
    }
    end = clock();
    cout << "deque_pop: " << (double)(end - start) << "\n";


    return 0;
}


