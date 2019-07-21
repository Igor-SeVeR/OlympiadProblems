#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e6 + 239;

vector<int> a[M];
vector<ll> pref[M];
int n, m, p;

ll getsum(int x1, int y1, int x2, int y2)
{
	return pref[x2 + 1][y2 + 1] + pref[x1][y1] - pref[x1][y2 + 1] - pref[x2 + 1][y1];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++)
	{
		a[i].resize(m);
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i <= n; i++)
	{
		pref[i].assign(m + 1, 0);
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0) continue;
			pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + a[i - 1][j - 1];
		}
	}        
	int cnt = 0;
	vector<pair<int, int> > now;
	ll ans = -1;
	for (int s = 0; s <= n + m && cnt < (6 * p); s++)
	{                     	
		for (int x = 0; x <= n; x++)
		{
			int y = (s - x);
			if (y < 0 || y > m) continue;
			now.push_back(make_pair(x, y));
		}
		for (int x = 0; x <= n; x++)
		{
			int y = (s - x);
			if (y < 0 || y > m) continue;   
			for (pair<int, int> t : now)
			{
				int xn = n - t.first;
				int yn = m - t.second;
				if (xn > x && yn > y)
				{
					ll sum = getsum(x, y, xn - 1, yn - 1);
					if (sum % (ll)p == 0)
						ans = max(ans, sum);
					sum = getsum(n - xn, m - yn, n - x - 1, m - y - 1);
					if (sum % (ll)p == 0)
						ans = max(ans, sum);
					cnt++;
				}
			} 
		}
	}
	if (ans == -1) ans = 0;
	cout << ans;
	return 0;
}