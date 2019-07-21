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

int main() 
{ 
	int64_t h, w, s, ans = 0;
	cin >> h >> w >> s;
	vector<pair<int64_t, int64_t>> v;
	for (int i = 1; i*i <= s; i++)
		if (s%i == 0)
			v.push_back({ i, s / i });

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].first <= h && v[i].second <= w)
			ans += (h - v[i].first + 1)*(w - v[i].second + 1);
		if (v[i].first <= w && v[i].second <= h && v[i].first != v[i].second)
			ans += (w - v[i].first + 1)*(h - v[i].second + 1);
	}
	cout << ans << endl;
	return 0;
}