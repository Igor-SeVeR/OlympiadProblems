#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

struct rect
{
  int x1, x2, y1, y2;
};

vector <vector <ll> > psum;

ll get(int x, int y)
{
  if (x < 0 || y < 0) return 0;
  return psum[x][y];
}

ll get(int x1, int x2, int y1, int y2)
{
  return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
}

bool operator < (const rect &a, const rect &b)
{
  ll s = get(a.x1, a.x2, a.y1, a.y2);
  ll t = get(b.x1, b.x2, b.y1, b.y2);
  if (s != t) return s > t;
  if (a.x1 != b.x1) return a.x1 < b.x1;
  if (a.x2 != b.x2) return a.x2 < b.x2;
  if (a.y1 != b.y1) return a.y1 < b.y2;
  return a.y2 < b.y2;
}

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector <vector <int> > a(n, vector <int> (m));
  psum.resize(n, vector <ll> (m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
      psum[i][j] = a[i][j] + (i ? psum[i - 1][j] : 0) + (j ? psum[i][j - 1] : 0) - (i && j ? psum[i - 1][j - 1] : 0);
    }
  }
  rect cur;
  cur.x1 = 0, cur.x2 = n - 1, cur.y1 = 0, cur.y2 = m - 1;
  set <rect> q;
  q.insert(cur);
  while (!q.empty())
  {
    auto it = *q.begin();
    if (get(it.x1, it.x2, it.y1, it.y2) % p == 0)
    {
      cout << get(it.x1, it.x2, it.y1, it.y2) << '\n';
      return 0;
    }
    q.erase(q.begin());
    if (it.x1 + 1 <= it.x2)
    {
      q.insert({it.x1 + 1, it.x2, it.y1, it.y2});
      q.insert({it.x1, it.x2 - 1, it.y1, it.y2});
    }
    if (it.y1 + 1 <= it.y2)
    {
      q.insert({it.x1, it.x2, it.y1 + 1, it.y2});
      q.insert({it.x1, it.x2, it.y1, it.y2 - 1});
    }
  }
  cout << 0 << '\n';
  return 0;
}
