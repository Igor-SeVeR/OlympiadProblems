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

void solve() {
	string s;
	cin >> s;
	int ans = 1;
	for (int i = 0; i < szof(s); i += 3) {
		int num = 0;
		for (int j = 0; j < 3; ++j) {
			num = num * 10 + s[i + j] - '0';
		}
		int cnt = 0;
		if (('a' <= num && num <= 'z') || ('A' <= num && num <= 'Z')) {
			cnt++;
		} else {
			if (s[i] == '1') {
				num %= 100;
				if (('a' <= num && num <= 'z') || ('A' <= num && num <= 'Z')) {
					++cnt;
				}
			} else {
				if (s[i + 1] == '1') {
					int val = (s[i] - '0') * 10 + s[i + 2] - '0';
					if (('a' <= val && val <= 'z') || ('A' <= val && val <= 'Z')) {
						++cnt;
					}
				} else if (s[i + 2] == '1') {
					int val = (s[i] - '0') * 10 + s[i + 1] - '0';
					if (('a' <= val && val <= 'z') || ('A' <= val && val <= 'Z')) {
						++cnt;
					}
				}
			}
		}

		ans = (ll) ans * cnt % MOD;
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
