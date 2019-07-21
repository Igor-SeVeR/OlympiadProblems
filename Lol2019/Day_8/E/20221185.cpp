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
vector<int> g[N];
set<int> res;
bool flag;


void dfs(int v, int parent = -1) {
	if (u[v])
		return;
	u[v] = 1;
	tin[v] = fup[v] = ++timer;
	int children = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == parent)
			continue;
		if (u[to]) {
			fup[v] = min(fup[v], tin[to]);
		}
		else {
			bool old = u[y];
			dfs(to, v);

			++children;
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] >= tin[v] && parent != -1 && !old && u[y]) {
				res.insert(v + 1);
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
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin >> x >> y;
	--x;
	--y;
	dfs(x);
	cout << res.size() << endl;
	for (auto &i : res)
		cout << i << endl;
	return 0;
}