#include <iostream>
#include <deque>

using namespace std;

struct Person {
    int num;
    string name;
};

int main()
{
    string nameList[] = { "Person1","Person2", "Person3", "Person4", "Person5" };
    deque<Person> waitingList;
    for (int i = 1; i <= 5; i++) {
        waitingList.emplace_back(Person{ i,nameList[i-1] });
    }

    //줄 기다린 사람
    for (int i = 1; i <= 3; i++) {
        Person temp = waitingList.front();
        waitingList.pop_front();
        cout << temp.num << " " << temp.name << endl;
    }

    //나간사람
    for (int i = 1; i <= 2; i++) {
        waitingList.pop_back();
    }
}
