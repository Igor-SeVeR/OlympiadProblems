#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;
int n, m, k, x, y, v[200100], fa[200100], mx[200100], ans;
map<int, int> mp[200100];

int ask(int x)
{
	return fa[x] == x ? x : fa[x] = ask(fa[x]);
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		cin >> v[i], fa[i] = i;
	for (int i = 1; i <= m; ++i)
		cin >> x >> y, fa[ask(x)] = ask(y);
	for (int i = 1; i <= n; ++i)
		mx[ask(i)] = max(mx[ask(i)], ++mp[ask(i)][v[i]]);
	ans = n;
	for (int i = 1; i <= n; ++i)
		ans -= mx[i];
	cout << ans << endl;
	return 0;
}