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
#define mp make_pair
#define pb push_back
#define NAME ""
#define y1 y1_423
#define list lista

using namespace std;

typedef long long ll;
typedef long double ld;

template<typename T>
ostream& operator << (ostream& cout, const vector<T> &a) {
	if ((int)a.size() == 0) {
		return (cout << "()");
	}
	cout << "(" << a[0];
	for (int i = 1; i < (int)a.size(); i++) {
		cout << "; " << a[i];
	}
	return (cout << ")");
}

template<typename T>
ostream& operator << (ostream& cout, const set<T> &a) {
	if ((int)a.size() == 0) {
		return (cout << "{}");
	}
	auto it = a.begin();
	cout << "{" << *it;
	++it;
	for (; it != a.end(); ++it) {
		cout << "; " << *it;
	}
	return (cout << "}");
}

template<typename T>
ostream& operator << (ostream& cout, const multiset<T> &a) {
	if ((int)a.size() == 0) {
		return (cout << "{}");
	}
	auto it = a.begin();
	cout << "{" << *it;
	++it;
	for (; it != a.end(); ++it) {
		cout << "; " << *it;
	}
	return (cout << "}");
}

template<typename T1, typename T2>
ostream& operator << (ostream& cout, const pair<T1, T2> &a) {
	return cout << "(" << a.first << "; " << a.second << ")";
}

const int nmax = 2000 * 1000;
const int inf = 2000 * 1000 * 1000;
const ll infl = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const int mod = 1000 * 1000 * 1000 + 7;
const ld pi = acos(-1.0);

int n, c, sz;
vector<int> a[nmax];
int cmp[nmax], sum[nmax];

int main() {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen(NAME".in", "r", stdin);freopen(NAME".out", "w", stdout);
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sz);
		a[i].resize(sz);
		for (int j = 0; j < sz; j++) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		cmp[i] = -1;
		for (int j = 0; j < (int)min(a[i].size(), a[i + 1].size()); j++) {
			if (a[i][j] != a[i + 1][j]) {
				cmp[i] = j;
				break;
			}
		}
		if (cmp[i] == -1) {
		    if (a[i].size() > a[i + 1].size()) {
		        cout << -1 << endl;
		        return 0;
		    }
		    sum[0]++;
		    continue;
		}
		if (a[i][cmp[i]] < a[i + 1][cmp[i]]) {
			sum[0]++;
			sum[c - a[i + 1][cmp[i]]]--;
			sum[c - a[i][cmp[i]]]++;
			sum[c]--;
		} else {
			sum[c - a[i][cmp[i]]]++;
			sum[c - a[i + 1][cmp[i]]]--;
		}
	}
	int cnt = 0;
	for (int i = 0; i < c; i++) {
		cnt += sum[i];
		if (cnt == n - 1) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}

