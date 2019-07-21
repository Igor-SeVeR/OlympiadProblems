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

const int N = 3000 + 7;
const int M = 998244353;

inline int add(int a, int b)
{
  a += b;
  if (a < 0) a += M;
  if (a >= M) a -= M;
  return a;
}

inline int mul(int a, int b)
{
  return (a * (ll) b) % M;
}

vector <pair <int, int> > g[N];
int dp[N][N][2];
int sz[N];
int cur_dp[N][2];
int go[N][2];
int c[N][N];

void dfs(int v, int pr)
{
  sz[v] = 1;
  vector <pair <int, int> > childs;
  for (auto c : g[v])
  {
    int to = c.first;
    if (to != pr)
    {
      dfs(to, v);
      sz[v] += sz[to];
      childs.push_back({to, c.second == to});
    }
  }
  for (int i = 0; i <= sz[v]; i++)
  {
    for (int t = 0; t < 2; t++)
    {
      cur_dp[i][t] = 0;
    }
  }
  cur_dp[1][0] = 1;
  int me = 1;
  for (auto t : childs)
  {
    int to = t.first, good = t.second;
    for (int cur = 1; cur <= me; cur++)
    {
      for (int chet = 0; chet < 2; chet++)
      {
        for (int save = good; save < 2; save++)
        {
          int flip = (save && !good);
          for (int he = 1; he <= sz[to]; he++)
          {
            for (int he_chet = 0; he_chet < 2; he_chet++)
            {
              if (save)
              {
                int val = cur_dp[cur][chet];
                val = mul(val, c[me - cur + sz[to] - he][sz[to] - he]);
                val = mul(val, c[cur + he - 1][he]);
                go[cur + he][chet ^ he_chet ^ flip] = add(go[cur + he][chet ^ he_chet ^ flip], mul(val, dp[to][he][he_chet]));
              }
              else
              {
                int val = cur_dp[cur][chet];
                val = mul(val, c[sz[to]][he]);
                val = mul(val, c[me - cur + sz[to]][sz[to]]);
                go[cur][chet ^ he_chet] = add(go[cur][chet ^ he_chet], mul(val, dp[to][he][he_chet]));
              }
            }
          }
        }
      }
    }
    me += sz[to];
    for (int i = 0; i <= me; i++)
    {
      for (int t = 0; t < 2; t++)
      {
        cur_dp[i][t] = go[i][t];
        go[i][t] = 0;
      }
    }
  }
  for (int i = 0; i <= me; i++)
  {
    for (int t = 0; t < 2; t++)
    {
      dp[v][i][t] = cur_dp[i][t];
    }
  }
}

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  c[0][0] = 1;
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i)
      {
        c[i][j] = add(c[i][j], c[i - 1][j]);
      }
      if (i && j)
      {
        c[i][j] = add(c[i][j], c[i - 1][j - 1]);
      }
    }
  }
  for (int i = 1; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back({b, b});
    g[b].push_back({a, b});
  }
  dfs(0, -1);
  int ans = 0;
  for (int i = 1; i <= sz[0]; i++)
  {
    for (int t = 0; t < 2; t++)
    {
      int val = dp[0][i][t];
      val = mul(val, c[sz[0]][i]);
      if (t == 0)
      {
        ans = add(ans, val);
      }
      else
      {
        ans = add(ans, -val);
      }
    }
  }
  cout << ans << '\n';
}
