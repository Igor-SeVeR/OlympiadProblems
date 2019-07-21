#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> del;
int nod[1500][1500];

int gcd(int a, int b) {
	while (b != 0) {
		a %= b;
		int c = a;
		a = b;
		b = c;
	}
	return a;
}

int f(int l, int k, int last, int p) {
	if (k == 0) {
		return 1;
	}
	int ans = 0;
	for (int i = l; i <= del.size() - k; i++) {
		int c = p;
		for (int j = 0; c > 0 && j < k; j++) {
			c /= del[i];
		}
		if ((nod[last][i] == 1) && c != 0) {
			ans += f(i + 1, k - 1, i, p / del[i]);
		}
	}
	return ans;
}

int main() {
	int k;
	cin >> n >> k;
	int i;
	for (i = 1; i * i < n; i++) {
		if (n % i == 0) {
			del.push_back(i);
			del.push_back(n / i);
		}
	}
	if (i * i == n) {
		del.push_back(i);
	}
	sort(del.begin(), del.end());
	for (int z = 0; z < del.size(); z++) {
		for (int j = z; j < del.size(); j++) {
			nod[z][j] = gcd(del[z], del[j]);
		}
	}
	cout << f(0, k, 0, n);
	//system("pause");
}