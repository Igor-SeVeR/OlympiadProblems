#include <iostream>
#include <algorithm>
using namespace std;

int n, L;
int arr[201][50001];

bool f(int mid, int i1, int i2) {
	int amount1 = (upper_bound(arr[i1] + 1, arr[i1] + L + 1, mid) - arr[i1]) - 1, 
		amount2 = (upper_bound(arr[i2] + 1, arr[i2] + L + 1, mid) - arr[i2]) - 1;
	return (amount1 + amount2) < L;
}

int bin(int i1, int i2) {
	int left = min(arr[i1][1], arr[i2][1]), right = (int)1e9, mid;
	while (left < right) {
		mid = (right - left) / 2 + left;
		if (f(mid, i1, i2)) left = mid + 1;
		else right = mid;
	}	
	return left;
}

int main() {
	cin >> n >> L;
	
	int x, d, a, c, m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> d >> a >> c >> m;
		for (int j = 1; j <= L; j++, x += d, d = (a * d + c) % m)
			arr[i][j] = x;
	}
	
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			cout << bin(i, j) << "\n";
	
	system("pause");
	return 0;
}