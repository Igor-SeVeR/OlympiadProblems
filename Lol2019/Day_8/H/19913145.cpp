#include <bits/stdc++.h>

using namespace std;

vector < vector < pair <int, int> > > g(20000);
vector <int> d(20000, 0);
vector <int> up(20000, 0);
vector <bool> used(20000, false);
vector <int> bridge;

void dfs(int u, int num, int l){
    d[u] = l;
    used[u] = true;
    up[u] = l;
    for (int i = 0; i < g[u].size(); ++i){
        if (used[g[u][i].first] == false){
            dfs(g[u][i].first, g[u][i].second, l + 1);
            if (up[g[u][i].first] >= d[g[u][i].first]){
                bridge.push_back(g[u][i].second);
            }
            up[u] = min(up[u], up[g[u][i].first]);
        }
        else{
            if (g[u][i].second != num){
                up[u] = min(up[u], d[g[u][i].first]);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        g[a-1].push_back({b-1, i});
        g[b-1].push_back({a-1, i});
    }
    for (int i = 0; i < n; ++i){
        if (used[i] == false){
            dfs(i, -1, 0);
        }
    }
    sort(bridge.begin(), bridge.end());
    cout << bridge.size() << endl;
    for (int i = 0; i < bridge.size(); ++i){
        cout << bridge[i] << ' ';
    }
}
