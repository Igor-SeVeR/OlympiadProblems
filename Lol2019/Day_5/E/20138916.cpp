#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, k;
  cin >> k >> n;
  vector<int> where(n);
  set<int> empty;
  for (int i = 0; i < k; ++i)
    empty.insert(i);
  vector<pair<int, int>> events(2 * n);
  for (int i = 0; i < n; ++i){
    int t1, t2;
    cin >> t1 >> t2;
    events[2 * i + 0] = {t1, +i + 1};
    events[2 * i + 1] = {t2 + 1, -i - 1};
  }
  bool pos = true;
  int cant = 0;
  sort(events.begin(), events.end());
  for (int i = 0; i < events.size(); ++i){
    if (events[i].second < 0){
      empty.insert(where[-1 - events[i].second]);
    } else if (empty.size() == 0){
      pos = false;
      cant = events[i].second;
      break;
    } else {
      auto tmp = empty.begin();
      where[events[i].second - 1] = *tmp;
      empty.erase(tmp);
    }
  }
  if (!pos)
    cout << 0 << " " << cant;
  else {
    for (int i = 0; i < n; ++i)
      cout << where[i] + 1 <<  "\n";
  }
  return 0;
}