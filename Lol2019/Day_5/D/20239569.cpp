#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <stdint.h>
#include <cstdint>
#include <math.h>
#include <cmath>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

#define m_p make_pair
#define all(x) x.begin(), x.end()
#define rep(from, i, to) for (int i = from; i < to; ++i)
#define pii pair <int, int>
#define pll pair <ll, ll>

const int INF = 1000000007;
const int MOD = 1000000007;
const int SIZE = 10010;


struct edge {
	bool buf; // 18, death
	int a, b, c, ind;
	edge() : buf(0), a(0), b(0), c(0), ind(0) {}
	edge(bool buf, int a, int b, int c, int ind) :
		buf(buf), a(a), b(b), c(c), ind(ind) {}
};


char check(int a, int b, int c, int a2, int b2, int c2) { // 1: second > first
	if (a == a2 && b == b2 && c == c2)
		return 2;
	if (c2 > c)
		return 1;
	if (c2 < c)
		return 3;
	if (b2 > b)
		return 1;
	if (b2 < b)
		return 3;
	if (a2 > a)
		return 1;
	return 3;
}


bool cmp(edge a, edge b) {
	char chk = check(a.a, a.b, a.c, b.a, b.b, b.c);
	if (chk == 2) {
		return a.buf > b.buf;
	}
	return (chk == 1 ? 1 : 0);
}


int n;
vector <edge> v;
set <int> rs;
bool buf;


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;

	rep(0, i, n) {
		int a, b, c, a2, b2, c2;
		cin >> a >> b >> c >> a2 >> b2 >> c2;
		if (check(a, b, c + 18, a2, b2, c2) != 1) // death before 18
			continue;
		v.push_back(edge(0, a, b, c + 18, i + 1));
		if (check(a, b, c + 80, a2, b2, c2) != 1) // death before 80
			v.push_back(edge(1, a2, b2, c2, i + 1));
		else
			v.push_back(edge(1, a, b, c + 80, i + 1));
	}

	sort(all(v), cmp);

	rep(0, i, v.size()) {
		if (!v[i].buf) {
			rs.insert(v[i].ind);
		}
		else {
			buf = 1;
			for (set<int>::iterator j = rs.begin(); j != rs.end(); ++j) {
				cout << *j << " ";
			}
			cout << "\n";
			while ((i < v.size()) && v[i].buf) {
				rs.erase(v[i].ind);
				i++;
			}
			if (i < v.size()) {
				rs.insert(v[i].ind);
			}
		}
	}

	if (!buf)
		cout << 0;

	return 0;
}
