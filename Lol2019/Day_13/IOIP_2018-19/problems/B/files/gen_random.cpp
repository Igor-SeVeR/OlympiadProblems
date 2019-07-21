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

	int w = atoi(argv[1]);
	int n = atoi(argv[2]);
	int l1 = atoi(argv[3]);
	int m = atoi(argv[4]);
	int l2 = atoi(argv[5]);

	cout << w << " " << n << " " << m << "\n";
	for (int i = 0; i < n; ++i) {
		cout << rnd.next(1, l1);
		if (i < n - 1) {
			cout << " ";
		}
	}
	cout << "\n";

	for (int i = 0; i < m; ++i) {
		cout << rnd.next(1, l2);
		if (i < m - 1) {
			cout << " ";
		}
	}
	cout << "\n";

	return 0;
}