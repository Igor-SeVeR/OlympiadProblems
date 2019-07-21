#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ull unsigned long long

using namespace std;

ull f(int n) {
	if (n <= 0) {
		return 1;
	}
	return n * f(n - 1);
}

ull r(int n, int k, int l) {
	if (k == 0) {
		return 1;
	}
	ull s = 0;
	for (int i = n + 1; i < l; i++) {
		s += r(i, k - 1, l);
	}
	return s;
}

int main() {
	int n, k;
	cin >> n >> k;
	ull v = f(n) / f(n - k);
	cout << v * r(-1, k, n);
}
