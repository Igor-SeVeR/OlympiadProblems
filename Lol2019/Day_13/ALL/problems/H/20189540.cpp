#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstdio>
#include<deque>
#include<queue>
#include<stack>
#include<random>
#include<numeric>
#include<functional>
#include<bitset>
#include<initializer_list>
#include<utility>
#include<tuple>
#include<limits>
#include<chrono>
#include<cassert>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<iterator>
#include<array>
#include<algorithm>
#include<cmath>
#include<complex>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<cstdint>
#include<forward_list>
#include<climits>
#include<cfloat>
#include<cstring>
#include<ctime>
#include<string_view>
#include<valarray>
#include<optional>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, p1, v1, p2, v2;
	cin >> n >> k >> p1 >> v1 >> p2 >> v2;
	--p1;
	--p2;
	int ans = 0; 
	for (int x = 1; x <= k; ++x) {
		for (int y = 1; y <= k; ++y) {
			for (int z = 1; z <= k; ++z) {
				vector<int> a(n);
				a[0] = x;
				a[1] = y;
				a[2] = z;
				for (int i = 3; i < n; ++i) {
					a[i] = k - a[i - 1] - a[i - 2];
				}
				bool flag = true;
				for (int i = 0; i < n; ++i) {
					flag &= (a[i] >= 1 && a[i] <= k);
				}
				for (int i = 2; i < n; ++i) {
					flag &= (a[i] + a[i - 1] + a[i - 2] == k);
				}
				flag &= (a[p1] == v1);
				flag &= (a[p2] == v2);
				if (flag) {
					++ans;
				}
			}
		}
	}
	cout << ans;
	return 0;
}