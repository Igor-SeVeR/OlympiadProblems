#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
#ifdef DEBUG
  freopen("input", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<pair<int, int>>> gr(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    gr[u].emplace_back(v, 1);
    gr[v].emplace_back(u, 0);
  }

  vector<int> dp(1 << n);
  dp[0] = 1;
  for (int mask = 0; mask < 1 << n; ++mask) {
    for (int v = 0; v < n; ++v) {
      int nmask = mask | (1 << v);
      if (nmask == mask) {
        continue;
      }

      bool ok = true;
      for (const auto& e : gr[v]) {
        if (mask & (1 << e.first)) {
          if (e.second == 1) {
            ok = false;
          }
        } else {
          if (e.second == 0) {
            ok = false;
          }
        }
      }

      if (ok) {
        dp[nmask] += dp[mask];
        if (dp[nmask] >= MOD) {
          dp[nmask] -= MOD;
        }
      }
    }
  }

  cout << dp[(1 << n) - 1] << endl;

  return 0;
}
