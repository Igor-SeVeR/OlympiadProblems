# include <stdio.h>
# include <iostream>
# include <algorithm>
# include <math.h>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, l, r, m, t;
	int a[19999], b[19999];
	cin >> n >> k;
	n--;
	k--;
	for (int i = 0; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= k; i++) cin >> b[i];
	for (int i = 0; i <= k; i++) {
		l = -1;
		r = n + 1;
		while (r > l + 1) {
			m = (l + r) / 2;
			if (a[m] < b[i]) l = m;
			else r = m;
		}
		t = r;
		l = -1;
		r = n + 1;
		while (r > l + 1) {
			m = (l + r) / 2;
			if (a[m] <= b[i]) l = m;
			else r = m;
		}
		if (r <= t) cout << 0 << endl;
		else cout << t + 1 << " " << r << endl;
	}
	return 0;
}
