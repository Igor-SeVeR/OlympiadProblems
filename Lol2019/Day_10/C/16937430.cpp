#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)

signed main() {
    string s;
    int k, ans = 0;
    cin >> s >> k;
    int n = s.size();
    set <int> pos;
    vector <int> lst(30, -1), nx(n, -1);
    for (int i = n - 1; i >= 0; --i) {
        nx[i] = lst[s[i] - 'a'];
        lst[s[i] - 'a'] = i;
    }
    rep(i, 0, n) {
        for (int j : pos) {
            if (s[j] == s[i]) {
                pos.erase(j);
                break;
            }
        }
        if (nx[i] != -1) {
            pos.insert(i);
            ++ans;
            if (pos.size() > k) {
                --ans;
                int mxi = -1;
                for (int j : pos) {
                    if (mxi == -1 || nx[j] > nx[mxi]) {
                        mxi = j;
                    }
                }
                pos.erase(mxi);
            }
        }
    }
    cout << ans << '\n';
}
