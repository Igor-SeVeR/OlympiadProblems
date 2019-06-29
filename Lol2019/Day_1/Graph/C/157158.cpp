#include <bits/stdc++.h>

#define fr first
#define sc second
#define mp make_pair

using namespace std;

int n, m, cv = -1, ans;
int bol[110][110], a[110][110];
pair <int, int> c[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector <int> g[10010];
bool bob[10010];

void dfs(int x, int y) {
    bol[x][y] = cv;
    for (int i = 0; i < 4; i++) {
        int xx = x + c[i].fr, yy = y + c[i].sc;
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && bol[xx][yy] == -1 && a[x][y] == a[xx][yy]) {
            dfs(xx, yy);
        }
    }
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            bol[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bol[i][j] == -1) {
                cv++;
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int xx = i + c[k].fr, yy = j + c[k].sc;
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[i][j] > a[xx][yy]) {
                    g[bol[i][j]].push_back(bol[xx][yy]);
                }
            }
        }
    }
    for (int i = 0; i <= cv; i++) {
        if (g[i].size() == 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
