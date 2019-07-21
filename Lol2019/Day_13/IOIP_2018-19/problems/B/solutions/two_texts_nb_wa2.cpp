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


void solve() {
	int w, n, m;
	cin >> w >> n >> m;
	vector<int> arr1;
	int maxl1 = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr1.push_back(num);
		maxl1 = max(maxl1, num);
	}
	vector<int> arr2;
	int maxl2 = 0;
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		arr2.push_back(num);
		maxl2 = max(maxl2, num);
	}

	int l = maxl1 - 1, r = w - maxl2;
	int ans = INF;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		int l1 = 1, l2 = 1;
		int cur = 0;
		for (int num : arr1) {
			if (cur + num > mid) {
				cur = num + 1;
				++l1;
			} else {
				cur += num + 1;
			}
		}
		cur = 0;
		for (int num : arr2) {
			if (cur + num > w - mid) {
				cur = num + 1;
				++l2;
			} else {
				cur += num + 1;
			}
		}
		// cerr << mid << " " << l1 << " " << l2 << endl;
		ans = min(ans, max(l1, l2));
		if (l1 > l2) {
			l = mid;
		} else {
			r = mid;
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
