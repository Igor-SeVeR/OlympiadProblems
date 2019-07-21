#include <iostream>
#include <deque>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str, num = "", x;
	deque <string> first;
	deque <string> second;
	char doing;
	for (int i = 0; i < n; i++) {
		cin >> doing;
		if (doing != '-') {
			cin >> num;
		}	
		if (doing == '+') {
			second.push_back(num);
		}
		else if (doing == '*') {
			second.push_front(num);
		}
		else {
			cout << first.front() << endl;
			first.pop_front();
		}
		if (second.size() > first.size()) {
			x = second.front();
			first.push_back(x);
			second.pop_front();
		}
		num = "";
	}
	//system("pause");
	return 0;
}