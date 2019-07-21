#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;


void swap(int &a, int &b) {
	int c = b;
	b = a;
	a = c;
}


void reverse(int a[], int i, int j) {
	for (int k = 0; k < (j - i) / 2 + 1; k++) {
		int c = a[i + k];
		a[i + k] = a[j - k];
		a[j - k] = c;
	}
}


int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int i = n - 2;
	bool flag = true;
	while (i >= 0 && flag) {
		if (a[i] < a[i + 1]) {
			int minim = i + 1;
			for (int j = i + 1; j < n; j++)
				if (a[j] > a[i] && a[j] < a[minim])
					minim = j;
			swap(a[minim], a[i]);
			reverse(a, i + 1, n - 1);
			flag = false;
		}
		i--;
	}
	if (flag) {
		for (int i = 1; i <= n; i++)
			a[i - 1] = i;
	}
	for (int x : a)
		cout << x << " ";
	return 0;
}