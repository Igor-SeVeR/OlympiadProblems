#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>
#include <numeric> 

#define int long long
#define pb push_back
using namespace std;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, l = 0, r = 0, ans = 1e18;
	cin >> n;
	pair<int, int> p;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> m;
	vector<int> v1(m);
	for (int i = 0; i < m; i++) {
		cin >> v1[i];
	}
	while (l != n && r != m) {
		if (abs(v[l] - v1[r]) < ans) {
			ans = abs(v[l] - v1[r]);
			p.first = v[l], p.second = v1[r];
		}
		if (v[l] < v1[r]) {
			l++;
		}
		else {
			r++;
		}
	}
	cout << p.first << " " << p.second;
}