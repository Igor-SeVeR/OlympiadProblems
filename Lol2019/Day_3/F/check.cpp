#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <ctime>
#include <string>
#include <cstring>
#include "testlib.h"
#define mp make_pair
#define pb push_back
#define NAME ""
#define y1 y1_423
#define list lista

using namespace std;

typedef long long ll;
typedef long double ld;


vector<int> a[1000 * 1000];
int n, c;

bool readAns(InStream& in) {
	int answ = in.readInt(-1, c - 1);
	if (answ == -1) {
		return false;
	}
	for (int i = 0; i < n - 1; i++) {
		int ind = -1;
		for (int j = 0; j < (int)min(a[i].size(), a[i + 1].size()); j++) {
			if (a[i][j] != a[i + 1][j]) {
				ind = j;
				break;
			}
		}
		if (ind == -1) {
			if (a[i].size() > a[i + 1].size()) {
				quitf(_wa, "%d-th line is always bigger than %d-th\n", i + 1, i + 2);
			} else {
				continue;
			}
		}
		if ((a[i][ind] + answ) % c > (a[i + 1][ind] + answ) % c) {
			quitf(_wa, "%d-th line is bigger than %d-th\n", i + 1, i + 2);
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	n = inf.readInt();
	c = inf.readInt();
	for (int i = 0; i < n; i++) {
		int sz = inf.readInt();
		a[i].resize(sz);
		for (int j = 0; j < sz; j++) {
			a[i][j] = inf.readInt() - 1;
		}
	}
	bool pans = readAns(ouf);
	bool jans = readAns(ans);
	if (pans == jans) {
		quitf(_ok, "Ok");
	} else if (pans && !jans) {
		quitf(_fail, "Contestant found an answer but we didn't!");
	} else if (!pans && jans) {
		quitf(_wa, "Contestant didn't find an answer, but it exists");
	}
	return -1;
}
