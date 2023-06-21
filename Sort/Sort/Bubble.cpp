#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void Sort(vector<int>& list) {
    for (int i = list.size()-1; i >=0; i--) {
        for (int j = 0; j <i; j++) {
            if(list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
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
    int size = 10;
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
    ListPrint(list);
    cout << "after:" << endl;
    start = clock();
    Sort(list);
    end = clock();
    ListPrint(list);
    cout << "time: " << (double)(end - start) << endl;

}

