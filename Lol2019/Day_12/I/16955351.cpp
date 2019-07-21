#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> u;

void dfs(int v, int p) {
    u[v] = 1;
    for (auto &i: g[v]) {
        if (i != p) {
            if (u[i]) {
                cout << "NO";
                exit(0);
                break;
            }
            dfs(i, v);
        }
    }
}

int main() {
    int n;
    cin >> n;

    u.resize(n);
    g.resize(n);

    for (int i = 0 ;i < n; ++i) {
        for (int j  =0, x; j< n; ++j) {
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; ++i){
        if (!u[i]) dfs(i, i);
    }

    cout << "YES";
}
