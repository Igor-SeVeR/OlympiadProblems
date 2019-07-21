#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1000, M = 1000;

ll dp[N][M];
int locked[N][M];

int main() {
    int n, m;
    cin >> n >> m;

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> locked[i][j];
            if (!locked[i][j]) continue;
            if (i != 0 && locked[i-1][j]) {
                dp[i][j] = dp[i-1][j];
            }
            if (j != 0 && locked[i][j-1]) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    if (dp[n-1][m-1] == 0) {
        cout << "Impossible";
    }
    else cout << dp[n-1][m-1] << "\n";

    return 0;
}
