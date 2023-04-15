#include <iostream>
#include <queue>

using namespace std;

struct Person
{
    int num;
    string name;
};

int main()
{
    queue<Person> waitingList;
    string name[] = { "Person1","Person2", "Person3", "Person4", "Person5" };

    for (int i = 0; i < 5; i++) {
        waitingList.emplace(Person{ i + 1,name[i] });
    }

    while (!waitingList.empty()) {
        Person temp = waitingList.front();
        waitingList.pop();
        cout << temp.num << " " << temp.name << endl;
    }
    waitingList.
}
