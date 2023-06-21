#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
//앞에서부터 하나씩 정렬
// 정렬 안된부분에서 가장 작은 숫자를 선택해 맨 앞으로
void Sort(vector<int> &list) {

    for (int i = 0; i < list.size() - 1; i++) {
        int min = i;
        for (int j = i+1; j < list.size(); j++) {
            if (list[min] > list[j]) {
                min = j;
            }
        }
        int temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
    return;
}
void ListPrint(vector<int> list) {
    for (int i : list) {
        cout << i << " ";
    }
    cout << endl;
    return;
}
int main()
{
    int size = 10000;
    vector<int> list;
    clock_t start, end;

    for (int i = 0; i < size; i++) {
        list.push_back(i);
    }
    //랜덤 섞기
    int rannum;
    for (int i = 0; i < size; i++) {
        rannum = rand() % (size - 1);
        int temp = list[i];
        list[i] = list[rannum];
        list[rannum] = temp;
    }

    cout << "before:" << endl;
    //ListPrint(list);
    cout << "after:" << endl;
    start = clock();
    Sort(list);
    end = clock();
    //ListPrint(list);
    cout << "time: " << (double)(end - start) << endl;
    
}

