
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <sstream>
#include <queue>
using namespace std;

void gen(vector <int> r, int i, int n, int summ) {
	if (summ == n) {
		for (int j = 0; j < n && r[j] != 0; ++j) {
			cout << r[j] << ' ';
		}
		cout << "\n";
	}
	if (i == 0) {
		for (int j = 1; j <= n; ++j) {
			r[i] = j;
			gen(r, i + 1, n, summ + j);
			r[i] = 0;
		}
	}
	else {
		for (int j = 1; j <= r[i - 1]; ++j) {
			if (summ + j > n) {
				break;
			}
			else {
				r[i] = j;
				gen(r, i + 1, n, summ + j);
				r[i] = 0;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector <int> r(n, 0);
	gen(r, 0, n, 0);
}