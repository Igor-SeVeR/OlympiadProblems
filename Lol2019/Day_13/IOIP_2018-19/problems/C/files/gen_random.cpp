#include <bits/stdc++.h>
#include "testlib.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int l = atoi(argv[1]);
	int d = atoi(argv[2]);

	for (int i = 0; i < l; ++i) {
		int tmp = rnd.next(0, 26 * 2 - 1);
		char c;
		if (tmp < 26) {
			c = 'a' + tmp;
		} else {
			c = 'A' + tmp - 26;
		}

		vector<int> cur;
		int code = c;
		while (code) {
			cur.push_back(code % 10);
			code /= 10;
		}
		reverse(cur.begin(), cur.end());
		if (szof(cur) == 2) {
			cur.insert(cur.begin() + rnd.next(0, 2), d);
		}
		for (int num : cur) {
			cout << num;
		}
	}

	cout << "\n";

	return 0;
}