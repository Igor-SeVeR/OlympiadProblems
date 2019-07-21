#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1000000000;
 
int calcLines(vector<int> const& a, int w) {
    int lines = 1;
    int pos = 0;
 
    for (auto word : a) {
        if (pos + word <= w) {
            pos += word + 1;
        } else {
            lines++;
            pos = word + 1;
        }
        if (word > w) {
            return INF;
        }
    }
 
    return lines;
}
 
int solve(vector<int> const& a, vector<int> const& b, int w, int maxw) {
    return max(calcLines(a, w), calcLines(b, maxw - w));
}
 
int main() {
    ios_base::sync_with_stdio(false);
 
    int w, n, m;
    cin >> w >> n >> m;
 
    vector<int> a(n);
    vector<int> b(m);
 
    int mxA = 0;
    for (int i = 0; i < n ;i++) {
        cin >> a[i];
        mxA = max(mxA, a[i]);
    }
 
    int mxB = 0;
    for (int j = 0; j < m; j++) {
        cin >> b[j];
        mxB = max(mxB, b[j]);
    }
 
    int l = mxA;
    int r = w - mxB;
    while (r - l >= 3) {
        int tl = l + (r - l) / 3;
        int tr = r - (r - l) / 3;
 
        int sl = solve(a, b, tl, w);
        int sr = solve(a, b, tr, w);
 
        if (sl > sr) {
            l = tl;
        } else {
            r = tr;
        }
    }
 
    int ans = INF;
    for (int i = l; i <= r; i++) {
        ans = min(ans, solve(a,b,i,w));
    }
 
    cout << ans;
 
    return 0;
}