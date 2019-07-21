#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<pair<int, int>>> mass(200000);
set<int> ans;
bool visited[200000];
int cnt = 0, n, m, timer, enter[200000], ret[200000];

void dfs(int v, int p) {
    visited[v] = true;
    enter[v] = ret[v] = timer++;
    int children = 0;
    for (size_t i = 0; i < mass[v].size(); ++i) {
        int to = mass[v][i].first;
        if (to == p) continue;
        if (visited[to])
            ret[v] = min(ret[v], enter[to]);
        else {
            dfs(to, v);
            ret[v] = min(ret[v], ret[to]);
            if (ret[to] >= enter[v] && p != -1)
                ans.insert(v + 1);
            children++;
        }
    }
    if (p == -1 && children > 1) {
        ans.insert(v + 1);
    }
}

int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        mass[x - 1].push_back(make_pair(y - 1, i + 1));
        mass[y - 1].push_back(make_pair(x - 1, i + 1));
    }
    timer = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    cout << ans.size() << '\n';
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << ' ';
    }


    return 0;
}