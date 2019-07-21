// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 998244353;

void add(int& a, int b){
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

vector<vector<int>> arrcnk;

int cnk(int n, int k) {
	return arrcnk[n][k];
}

void solve() {
	int n;
	cin >> n;
	vector<vector<pii>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back({b, 0});
		graph[b].push_back({a, 1});
	}

	arrcnk = vector<vector<int>>(n + 1, vector<int>(n + 1));
	arrcnk[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			arrcnk[i][j] = arrcnk[i - 1][j];
			if (j) {
				add(arrcnk[i][j], arrcnk[i - 1][j - 1]);
			}
		}
	}

	map<vector<int>, pii> mem;
	vector<bool> used(n);
	vector<int> visited;

	function<void(int, int)> dfs = [&](int v, int p) {
		visited.push_back(v);
		for (pii to : graph[v]) {
			if (to.ff != p && !used[to.ff]) {
				dfs(to.ff, v);
			}
		}
	};

	function<pii(int)> rec = [&](int v) {
		visited.clear();
		dfs(v, -1);
		sort(visited.begin(), visited.end());
		if (mem.count(visited)) {
			return mem[visited];
		}
		auto& val = mem[visited];
		val.ff = szof(visited);

		auto mv = visited;
		for (int u : mv) {
			// cerr << v << " " << u << endl;
			bool fl = true;
			for (pii to : graph[u]) {
				if (!used[to.ff] && to.ss == 1) {
					fl = false;
					break;
				}
			}
			if (fl) {
				// cerr << "center " << v << " " << u << endl;
				used[u] = true;
				int left = szof(mv) - 1;
				int cur = 1;
				for (pii to : graph[u]) {
					if (!used[to.ff]) {
						auto tmp = rec(to.ff);
						cur = mult(cur, mult(cnk(left, tmp.ff), tmp.ss));
						left -= tmp.ff;
					}
				}
				add(val.ss, cur);
				used[u] = false;
			}
		}

		return val;
	};

	pii ans = rec(0);
	cout << ans.ss << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
