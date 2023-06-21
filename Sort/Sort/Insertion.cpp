#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
//앞에서부터 하나씩 정렬
//정렬 안된 부분에서 가장 앞에있는 숫자를 정렬된 배열의 적절한 위치로 삽입
void Sort(vector<int>& list) {
    for (int i = 1; i < list.size(); i++) {
        for (int j = i - 1; j >=0; j--) {
            if (list[j] < list[j+1]) {
                break;
            }
            int temp = list[j+1];
            list[j+1] = list[j];
            list[j] = temp;
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

