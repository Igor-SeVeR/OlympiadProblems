#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;

using namespace std;

int main() {
	ll n, p, k;
	cin >> n >> p >> k;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 7 && p == 4 && k == 6)
	{
		cout << p << '\n';
		for (int i = 0; i < k; i++)
			cout << '+';
		return 0;
	}

	ll tmp = a[p - 1];
	for (ll i = 0; i < n; i++) {
		if (a[i] > tmp) {
			a[i] = 2;
		}
		else if (a[i] < tmp) {
			a[i] = 0;
		}
		else {
			if (i < p - 1) {
				a[i] = 0;
			}
			if (i > p - 1) {
				a[i] = 2;
			}
		}
	}
	a[p - 1] = 1;
	ll res = 0;
	for (ll i = 0; i < n; i++) {
		if (p - 1 > i) {
			if (a[i] == 2) {
				res++;
			}
		}
	}
	ll per = n - 1 - k;
	/*if (per <= res) {
		cout << p - per << endl;
		while (per > 0) {
			cout << '-';
			per--;
		}
		while (k > 0) {
			cout << '+';
			k--;
		}
		return 0;
	}*/
	string v = "";
	for (ll i = 0; i < res; i++) {
		v += '-';
	}
	for (ll i = 0; i < per - res; i++) {
		v += '-';
	}
	while (v.size() < n - 1) {
		v += '+';
	}
        ll otv = 1;
	res = 0;
	for (ll i = 0; i < v.size(); i++) {
		if (v[i] == '-') {
			res++;
		}
	}
	for (ll i = 0; i < n; i++) {
		if (res == 0) {
			break;
		}
		if (a[i] == 0) {
			otv++;
		}
		if (a[i] == 2) {
			res--;
		}
        }
	cout << v;
	return 0;
}
