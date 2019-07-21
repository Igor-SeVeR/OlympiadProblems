#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  vector<pair<int, pair<int, int>>> events;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    events.push_back(make_pair(a, make_pair(0, i)));
    events.push_back(make_pair(b, make_pair(1, i)));
  }
  set<int> opened_segs;
  opened_segs.insert(-1);
  vector<int> dead_segs(n, 0);
  stable_sort(events.begin(), events.end());
  int ans = 0;
  int max_i = -1;
  for (int i = 0; i < events.size(); i++) {
    if (!events[i].second.first) {
      if (*opened_segs.rbegin() <= events[i].second.second) {
        dead_segs[*opened_segs.rbegin()] = 0;
        opened_segs.insert(events[i].second.second);
        max_i = events[i].second.second;
      } else {
        dead_segs[events[i].second.second] = 0;
        opened_segs.insert(events[i].second.second);
      }
    } else {
      if (opened_segs.find(events[i].second.second) != opened_segs.end()) {
        opened_segs.erase(opened_segs.find(events[i].second.second));
      }
      if (events[i].second.second == max_i) {
        ans++;
        max_i = -1;
      }
    }
  }
  cout << ans;
  return 0;
}