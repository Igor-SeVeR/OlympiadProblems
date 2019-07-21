#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, k, z = 0, x = 0, c = 0, v = 0;
	cin >> n >> k;
	vector <int> a(n);
	vector <int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i] <= k && a[i] != -1) {
				if (z < b[i]) {
					z = b[i];
					c = i;
				}
				x++;
			}
		}
		if (x == 0) {
			cout << v;
			return 0;
		}
		a[c] = -1;
		b[c] = -1;
		v++;
		k += z;
		x = 0;
		z = 0;
	}
	cout << n;
}