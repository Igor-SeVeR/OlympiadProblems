#define _CRT_SECURE_NO_WARNINGS
#define fr(i, l, r) for (int i = l; i < r; ++i)
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<deque>

typedef long long ll;

using namespace std;

const int N = 20200;

int n, m, x, y, u[N], timer, tin[N], fup[N];
vector<pair<int, int> > g[N], d;
vector<int> res;
map<pair<int, int>, short> q;


void dfs(int v, int parent = -1) {
	if (u[v])
		return;
	u[v] = 1;
	tin[v] = fup[v] = ++timer;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i].ff;
		if (to == parent)
			continue;
		if (u[to]) {
			fup[v] = min(fup[v], tin[to]);
		}
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				if (q[{v, to}] == 1)
					res.push_back(g[v][i].ss);
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	fr(i, 0, m) {
		cin >> x >> y;
		--x;
		--y;
		if (q[{x, y}] == 1 || q[{x, y}] == -1) {
			q[{x, y}] = -1;
			q[{y, x}] = -1;
			continue;
		}
		q[{x, y}] = 1;
		q[{y, x}] = 1;
		g[x].push_back(make_pair(y, i + 1));
		g[y].push_back(make_pair(x, i + 1));
	}
	fr(i, 0, n)
		dfs(i);
	sort(all(res));
	cout << res.size() << endl;
	fr(i, 0, res.size())
		cout << res[i] << ' ';
	return 0;
}