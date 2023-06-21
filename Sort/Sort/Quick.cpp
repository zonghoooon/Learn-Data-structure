#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int partition(vector<int>& list, int left, int right) {
    int pivot = list[left];
    int low=left, high = right+1;
    while (true) {
        do {
            low++;
        } while (list[low]< pivot&&low<=right);
        do {
            high--;
        } while (list[high] > pivot&&high >= left);

        if (low > high) break;
        int temp = list[low];
        list[low] = list[high];
        list[high] = temp;
    }
    int temp = list[left];
    list[left] = list[high];
    list[high] = temp;
    return high;

}
void Sort(vector<int>& list, int left, int right) {
    if (left < right) {
        int q = partition(list, left, right);
        Sort(list, left, q - 1);
        Sort(list, q + 1, right);
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
    Sort(list,0,size-1);
    end = clock();
    ListPrint(list);
    cout << "time: " << (double)(end - start) << endl;

}

