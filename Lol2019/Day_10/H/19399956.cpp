#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N];
int get(vector <bool> a, int k) {
    if (k <= 0) return 0;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i]) {
            ++cnt;
            if (cnt == k) return ans;
        }
        else {
            ++ans;
        }   
    }   
    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, p, k;
    cin >> n >> p >> k;
    --p;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < p; ++i) cnt += a[i] > a[p];
    int ost = n - 1 - cnt;
    int skip = min(k, ost);
    vector <bool> v;
    for (int i = p + 1; i < n; ++i) {
        v.push_back(a[i] >= a[p]);
    }   
    cout << p + 1 - cnt + get(v, n - 1 - cnt - skip) << '\n';
    for (int i = 0; i < n - 1 - skip; ++i) cout << '-';
    for (int i = 0; i < skip; ++i) cout << '+';
    cout << '\n';
}   