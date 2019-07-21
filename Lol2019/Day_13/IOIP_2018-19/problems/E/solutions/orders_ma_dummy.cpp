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
  vector<pair<int, int>> el(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> el[i].first >> el[i].second;
    --el[i].first;
    --el[i].second;
  }

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  int answer = 0;
  do {
    bool ok = true;
    for (const auto& e : el) {
      if (p[e.first] > p[e.second]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ++answer;
    }
  } while (next_permutation(begin(p), end(p)));

  cout << answer << endl;

  return 0;
}
