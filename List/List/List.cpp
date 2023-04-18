#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Person {
    int pnum;
    string pname;

    Person(int num) {
        pnum = num;
        pname = "Person" + to_string(num);
    }
};

int main()
{
    list<Person> waitingList;

    for (int i = 1; i <= 5; i++) {
        waitingList.push_back(Person(i));
    }

    for (auto i: waitingList) {
        cout << i.pnum << i.pname << endl;
    }
    waitingList.
}
