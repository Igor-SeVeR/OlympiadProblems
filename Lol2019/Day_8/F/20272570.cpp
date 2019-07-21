#include <iostream> 
#include <queue> 
#include <vector> 
#include <map>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

int n, timer = 0, flag = 1;
vector < vector <int> > a;
vector <int> d, fup, tin;

void dfs(int p, int pr) {
	d[p] = 1;
	fup[p] = tin[p] = timer++;
	for (int i = 0; i < n; ++i) if (a[p][i]) {
		if (pr == i) continue;
		if (d[i]) {
			fup[p] = min(fup[p], tin[i]);
		}
		else {
			dfs(i, p);
			fup[p] = min(fup[p], fup[i]);
			if (fup[i] > tin[p]) {
				if (a[p][i] == 1) flag = 0;
			}
		}
	}
}

vector < vector <int> > g;

void dfs2(int p, int pr) {
	d[p] = 1;
	for (int i = 0; i < n; ++i) {
		if (a[p][i]) {
			a[p][i]--;
			a[i][p]--;
			g[p][i]++; 
			if (!d[i]) dfs2(i, p);
		}
	}
}

int main() {
	int m;
	cin >> n >> m;
	a.resize(n, vector <int>(n, 0));
	vector < pair <int, int> > in;
	for (int i = 0; i < m; ++i) {
		int j, k;
		cin >> j >> k;
		in.push_back({ j - 1, k - 1 });
		if (!a[j - 1][k - 1]) a[j - 1][k - 1] = 1;
		else a[j - 1][k - 1] = 2;
		if (!a[k - 1][j - 1]) a[k - 1][j - 1] = 1;
		else a[k - 1][j - 1] = 2;
	}
	d.resize(n, 0);
	fup.resize(n, 0);
	tin.resize(n, 0);
	for (int i = 0; i < n; ++i) {
		if (!d[i]) dfs(i, -1);
	}
	if (flag) {
		d.clear();
		d.resize(n, 0);
		g.resize(n, vector <int> (n, 0));
		dfs2(0, -1);
		for (int i = 0; i < in.size(); ++i) {
			int x = in[i].first, y = in[i].second;
			if (g[x][y]) {
				cout << x + 1 << " " << y + 1 << "\n";
				g[x][y]--;
			}
			else if (g[y][x]) {
				cout << y + 1 << " " << x + 1 << "\n";
				g[y][x]--;
			}
			else {
				cout << x + 1 << " " << y + 1 << "\n";
			}
		}
	}
	else cout << 0;
}
