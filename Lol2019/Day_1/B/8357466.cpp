#include <bits/stdc++.h>

using namespace std;

int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> field(n, vector<int>(m));
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> field[i][j];
    }
  }
  deque<pair<int, int>> q;
  dist[0][0] = 0;
  q.emplace_back(0, 0);
  while (!q.empty()) {
    auto[x, y] = q.front();
    q.pop_front();
    for (int i = 0; i < 4; i++) {
      int cur_x = x;
      int cur_y = y;
      for (;;) {
        int new_x = cur_x + DX[i];
        int new_y = cur_y + DY[i];
        if (new_x < n && new_y < m && new_x >= 0 && new_y >= 0 && field[new_x][new_y] != 1) {
          cur_x = new_x;
          cur_y = new_y;
        } else {
          break;
        }
        if (field[new_x][new_y] == 2) {
          cout << dist[x][y] + 1;
          return 0;
        }
      }
      if (dist[cur_x][cur_y] > dist[x][y] + 1 && field[cur_x][cur_y] != 2) {
        dist[cur_x][cur_y] = min(dist[cur_x][cur_y], dist[x][y] + 1);
        q.emplace_back(cur_x, cur_y);
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (field[i][j] == 2)
        ans = min(ans, dist[i][j]);
    }
  }
  cout << ans;
  return 0;
}
