#include <iostream>
#include <string>

using namespace std;

int main() {

	string s;

	cin >> s;

	bool t = true;

	for (int i = 0; i < s.size(); i++)
		if (((int)s[i] < 97) || ((int)s[i] > 99))
			t = false;

	for (int i = 1; i < s.size(); i++)
		if ((s[i] == 'b') && (s[i - 1] == 'b'))
			t = false;

	for (int i = 1; i <= s.size() / 3; i++) {
		for (int j = 0; j <= s.size() - 3 * i; j++) {
			int cnt = 0;
			for (int k = j; k < j + i; k++) {
				if ((s[k] == s[k + i]) && (s[k] == s[k + 2 * i])) {
					cnt++;
				}
			}
			if (cnt == i)
				t = false;
		}
	}

	if (t == true)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}