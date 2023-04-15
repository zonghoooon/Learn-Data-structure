#include <iostream>
#include <stack>

using namespace std;

struct Book {
	int num;
	string name;
};

int main() {

	string bookName[] = {"book1","book2","book3","book4","book5"};

	stack<Book> bookStack;

	for (int i = 0; i < 5; i++) {
		Book temp;
		temp.num = i+1;
		temp.name = bookName[i];

		//스택에 넣기
		//bookStack.push(temp);
		//emplace 이용
		bookStack.emplace(Book{ i + 1, bookName[i] });
	}

	while (!bookStack.empty()) {
		Book temp = bookStack.top();
		bookStack.pop();
		cout << temp.num << " " << temp.name << endl;
	}
}