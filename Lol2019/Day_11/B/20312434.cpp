#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int a[101];
string biin(int n, int k) {
	string s;
	while (n > 0) {
		s.push_back((n % k) + '0');
		n = n / k;
	}
	reverse(s.begin(), s.end());
	return s;
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = n; i >= 1; i--) {
		cout << 0;
	}
	cout << endl;
	for (int i = 1; i <= pow(k, n - 1) - 1; i++) {
		int l = biin(i, k).length();
		for (int i = 1; i <= n - l; i++) {
			cout << 0;
		}
		cout << biin(i, k) << endl;
	}
	for (int i = pow(k, n - 1); i < pow(k, double(n)); i++) {
		int l = biin(i, k).length();
		for (int i = 1; i <= n - l; i++) {
			cout << 0;
		}
		cout << biin(i, k) << endl;
	}
	return 0;
}
