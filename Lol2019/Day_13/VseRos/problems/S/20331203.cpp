#include <algorithm>
#include <iostream>
#include <string.h>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;

const int MAXN = 1000000;
const ll INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const double EPS = 1e-7;

bool comp(ll a, ll b)
{
	return abs(a) > abs(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); cerr.tie(0);
	//SetConsoleCP(1251); // Для кириллицы
	//SetConsoleOutputCP(1251); // Для кириллицы
	ll n, max_i = 0LL;
	cin >> n;
	vector<ll> arr(n);
	for (ll i = 0LL; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > arr[max_i])
		{
			max_i = i;
		}
	}
	ll maxx = 0LL;
	for (ll i = max_i + 1LL; i < n - 1LL; i++)
	{
		if (arr[i] % 10LL == 5LL && arr[i] > arr[i + 1LL])
		{
			if (arr[i] > maxx)
			{
				maxx = arr[i];
			}
		}
	}
	sort(arr.begin(), arr.end());
	ll ans = 0LL;
	if (maxx == 0LL)
	{
		cout << ans << endl;
		return 0LL;
	}
	for (ll i = n - 1LL; i >= 0LL; i--)
	{
		if (arr[i] > maxx)
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	cout << ans + 1LL << endl;
	return 0LL;
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
