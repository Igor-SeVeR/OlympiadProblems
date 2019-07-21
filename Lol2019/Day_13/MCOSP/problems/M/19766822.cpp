#include<bits/stdc++.h>
  
using namespace std;
typedef long long ll;
typedef long double ld;
#define int long long
  
signed main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int A, B, C, n;
    cin >> A >> B >> C >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (A > C) {
        cout << A;
        return 0;
    }
    if (A + B <= C) {
        cout << A + B;
        return 0;
    }
    vector<bool> dp(A + B, false);
    vector<int> parent(A + B, -1);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = A + B - 1; j >= a[i]; --j) {
            if (dp[j - a[i]]) {
                dp[j] = dp[j - a[i]];
                parent[j] = i;
            }
        }
    }
    int w = -1;
    for (int i = C - A + 1; i < B; ++i) {
        if (dp[i]) {
            w = i;
            break;
        }
    }
    if (w == -1) {
        cout << A + B;
        return 0;
    }
    cout << A + w << '\n';
    /*vector<int> ans;
    while (w > 0) {
        ans.push_back(parent[w] + 1);
        w -= a[parent[w]];
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int c : ans) {
        cout << c << ' ';
    }
     */
}