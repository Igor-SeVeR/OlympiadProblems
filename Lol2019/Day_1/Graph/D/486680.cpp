#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	string x;
	cin >> x;
	int k;
	cin >> k;
	int s;
	cin >> s;
	vector<int> digits(s);
	for (int d = 0; d < s; d++) {
		cin >> digits[d];
	}
	sort(digits.begin(), digits.end());
	int r = 0;
	for (auto c : x) {
		r = (r * 10 + (c - '0')) % k;
	}
	vector<vector<int>> back(k);
	for (int m1 = 0; m1 < k; m1++) {
		for (auto d : digits) {
			int m2 = (m1 * 10 + d) % k;
			back[m2].push_back(m1);
		}
	}

	vector<int> len(k, -1);
	queue<int> q;
	len[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto m : back[x]) {
			if (len[m] == -1) {
				len[m] = len[x] + 1;
				q.push(m);
			}
		}
	}
	if (len[r] == -1) {
		cout << -1;
		return 0;
	}
	cout << x;
	while (r != 0) {
		for (auto d : digits) {
			int r2 = (r * 10 + d) % k;
			if (len[r2] == len[r] - 1) {
				cout << d;
				r = r2;
				break;
			}
		}
	}
	return 0;
}
