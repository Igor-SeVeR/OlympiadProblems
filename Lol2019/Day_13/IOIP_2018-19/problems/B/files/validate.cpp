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

int MAXW = 1000000000;
int MAXN = 100000;
int MAXL = MAXW;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	if (validator.group() == "1") {
		MAXW = 1000;
		MAXN = 1000;
		MAXL = 1000;
	}

	int w = inf.readInt(1, MAXW, "w");
	inf.readSpace();
	int n = inf.readInt(1, MAXN, "n");
	inf.readSpace();
	int m = inf.readInt(1, MAXN, "m");
	inf.readEoln();

	int maxl1 = 0, maxl2 = 0;
	for (int i = 0; i < n; ++i) {
		int l = inf.readInt(1, MAXL, format("l1_%d", i + 1));
		if (i < n - 1) {
			inf.readSpace();
		}
		maxl1 = max(maxl1, l);
	}
	inf.readEoln();

	for (int i = 0; i < m; ++i) {
		int l = inf.readInt(1, MAXL, format("l2_%d", i + 1));
		if (i < m - 1) {
			inf.readSpace();
		}
		maxl2 = max(maxl2, l);
	}

	inf.readEoln();

	inf.readEof();

	ensuref(maxl1 + maxl2 <= w, "solution should exist");

	return 0;
}