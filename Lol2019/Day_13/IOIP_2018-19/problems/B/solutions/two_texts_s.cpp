#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1000000000;
 
pair<int, int> calcLines(vector<int> const& a, int w) {
    int lines = 1;
    int pos = 0;
    int change = INF;
 
    for (auto word : a) {
        if (pos + word <= w) {
            pos += word + 1;
        } else {
            lines++;
            pos = word + 1;
            change = min(change, pos + word - w);
        }
        if (word > w) {
            return {INF, INF};
        }
    }
 
    return {lines, change};
}
 
int main() {
    ios_base::sync_with_stdio(false);
 
    int w, n, m;
    cin >> w >> n >> m;
    //w = 1e9;
    //n = 1e5;
    //m = 1e5;
 
    vector<int> a(n);
    vector<int> b(m);
 
    int mxA = 0;
    for (int i = 0; i < n ;i++) {
        cin >> a[i];
        //a[i] = 1e9 / 2 - 2;
        //a[i] = 1;
        mxA = max(mxA, a[i]);
    }
 
    int mxB = 0;
    for (int j = 0; j < m; j++) {
        cin >> b[j];
        //b[j] = 1;
        mxB = max(mxB, b[j]);
    }
 
    int l = mxA;
    int r = w - mxB + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
 
        int sa = calcLines(a, mid).first;
        int sb = calcLines(b, w - mid).first;
 
        if (sa == sb) {
            l = r = mid;
        } else if (sa < sb) {
            r = mid;
        } else {
            l = mid;
        }
    }
 
    int ans = INF;
    for (int i = max(mxA, l - 5); i <= min(r + 5, w - mxB); i++) {
        int sol = max(calcLines(a, i).first, calcLines(b, w-i).first);
        ans = min(ans, sol);
    }
 
    cout << ans;
 
    return 0;
}