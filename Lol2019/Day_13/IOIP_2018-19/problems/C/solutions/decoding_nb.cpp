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

const int MOD = 1000000007;
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
	string s;
	cin >> s;
	int ans = 0;
	for (int dig = 0; dig < 10; ++dig) {
		// int cur = 1;
		vector<int> d(2);
		d[0] = 1;
		for (int i = 0; i < szof(s); i += 3) {
			set<int> have;
			vector<int> next(2);
			for (int j = 0; j < 3; ++j) {
				if (s[i + j] - '0' == dig) {
					int num = 0;
					for (int k = 0; k < 3; ++k) {
						if (j != k) {
							num = num * 10 + s[i + k] - '0';
						}
					}
					if (('A' <= num && num <= 'Z') || ('a' <= num && num <= 'z')) {
						have.insert(num);
					}
				}
			}
			next[1] = mult(sum(d[0], d[1]), szof(have));
			int num = 0;
			for (int k = 0; k < 3; ++k) {
				num = num * 10 + s[i + k] - '0';
			}
			if (s[i] != '0' && (('A' <= num && num <= 'Z') || ('a' <= num && num <= 'z'))) {
				have.insert(num);
				next[0] = d[0];
				add(next[1], d[1]);
			}
			swap(d, next);
		}
		// cerr << dig << " " << d[0] << " " << d[1] << endl;
		add(ans, d[1]);
		if (dig == 0) {
			add(ans, d[0]);
		}
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
