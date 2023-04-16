#include <iostream>
#include <queue>

using namespace std;

struct Person {
    int money;
    string name;
    bool operator<(const Person i) const {
        return (money < i.money);
    }
};

int main()
{
    priority_queue<Person> waitingList;
    string name[] = { "person0","person1", "person2", "person3", "person4" };
    int wallet[] = {100,5000,2000,1500,10000};

    for (int i = 0; i < 5; i++) {
        waitingList.emplace(Person{wallet[i],name[i]});
    }

    while (!waitingList.empty()) {
        Person temp = waitingList.top();
        waitingList.pop();

        cout << temp.name << " " << temp.money << endl;
    }
    waitingList.
}
