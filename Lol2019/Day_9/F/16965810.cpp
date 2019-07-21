#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector <string> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    for (int cnt = 0; cnt < 2000; cnt++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < m - 1; k++) {
                int sqr = 0;
                sqr += f[j][k] == '#';
                sqr += f[j + 1][k] == '#';
                sqr += f[j][k + 1] == '#';
                sqr += f[j + 1][k + 1] == '#';
                if (sqr == 3) {
                    f[j][k] = '#';
                    f[j + 1][k] = '#';
                    f[j][k + 1] = '#';
                    f[j + 1][k + 1] = '#';
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += f[i][j] == '#';
    cout << cnt;
    return 0;
}

