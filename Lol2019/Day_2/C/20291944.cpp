#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int a, c = 0;
	queue<int> f, s;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		if (i < 5) {
			f.push(a);
		}
		else {
			s.push(a);
		}
	}
	while (!f.empty() && !s.empty() && c <= 1000000) {
		if (f.front() == 0 && s.front() == 9) {
			f.push(0);
			f.push(9);
		}
		else {
			if (f.front() == 9 && s.front() == 0) {
				s.push(9);
				s.push(0);
			}
			else {
				if (s.front() > f.front()) {
					s.push(f.front());
					s.push(s.front());
				}
				else {
					f.push(f.front());
					f.push(s.front());
				}
			}
		}
		s.pop();
		f.pop();
		c++;
	}
	if (c > 1000000) {
		cout << "botva";
	}
	else {
		if (s.empty()) {
			cout << "first";
		}
		else {
			cout << "second";
		}
		cout << " " << c;
	}
}
