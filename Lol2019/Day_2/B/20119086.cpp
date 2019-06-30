//#include <bits/stdc++.h>
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>

#define all(a) a.begin(), a.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool comp(int a)
{
	return a % 2 == 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	multiset<int> a;

	for (int i = 0; i < n; ++i)
	{
		int curVal;
		cin >> curVal;

		a.insert(curVal);
	}

	double res = 0;
	while (a.size() > 1)
	{
		int curVal = *a.begin() + *++a.begin();
		a.erase(a.begin());
		a.erase(a.begin());
		res += curVal * 0.05;
		a.insert(curVal);
	}

	cout << fixed << setprecision(2) << res;
	//system("pause");
	return 0;
}