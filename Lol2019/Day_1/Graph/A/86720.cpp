#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int color[101], g[101][101];
bool fail = false;
int n, m, x, y;

void dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && g[v][i] == 1) {
            dfs(i, 3-c);
        }
        if (color[i] == c && v != i && g[v][i] == 1)
            fail = true;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x-1][y-1] = 1;
        g[y-1][x-1] = 1;
    }
    for (int i = 0; i < n ; i++) {
        if (color[i] == 0)
            dfs(i, 1);
    }
    if (fail)
        cout << "NO";
    else{
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            if (color[i] == 1)
                cout << i+1 << " ";
    }
    return 0;
}
