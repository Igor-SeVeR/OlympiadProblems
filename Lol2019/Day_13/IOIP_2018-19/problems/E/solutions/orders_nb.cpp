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

void add(int& a, int b) {
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

	vector<vector<int>> cnk(n + 1, vector<int>(n + 1));
	cnk[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			cnk[i][j] = cnk[i - 1][j];
			if (j) {
				add(cnk[i][j], cnk[i - 1][j - 1]);
			}
		}
	}

	function<vector<int>(int, int)> dfs = [&](int v, int p) {
		vector<int> ret(1, 1);
		for (pii to : graph[v]) {
			if (to.ff != p) {
				auto tmp = dfs(to.ff, v);
				vector<int> next(szof(ret) + szof(tmp));
				if (to.ss == 0) {
					for (int i = szof(tmp) - 2; i >= 0; --i) {
						add(tmp[i], tmp[i + 1]);
					}
					for (int i = 0; i < szof(ret); ++i) {
						for (int j = 0; j < szof(tmp); ++j) {
							add(next[i + j], mult(ret[i], mult(tmp[j], mult(cnk[i + j][i], cnk[szof(next) - i - j - 1][szof(ret) - i - 1]))));
						}
					}
				} else {
					for (int i = 1; i < szof(tmp); ++i) {
						add(tmp[i], tmp[i - 1]);
					}
					for (int i = 0; i < szof(ret); ++i) {
						for (int j = 0; j < szof(tmp); ++j) {
							add(next[i + j + 1], mult(ret[i], mult(tmp[j], mult(cnk[i + j + 1][i], cnk[szof(next) - i - j - 2][szof(ret) - i - 1]))));
						}
					}
				}
				swap(next, ret);
			}
		}
		return ret;
	};

	auto tmp = dfs(0, -1);

	int ans = 0;
	for (int num : tmp) {
		add(ans, num);
	}

	cout << ans << "\n";
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
