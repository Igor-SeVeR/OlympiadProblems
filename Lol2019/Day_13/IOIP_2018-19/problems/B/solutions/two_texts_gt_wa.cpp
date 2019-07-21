#include <bits/stdc++.h>
 
using namespace std;
 
int calc(vector <int> &a, int w) {
    int ans = 1;
    int pos = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] > w) return (int)1e9;
        if (pos + a[i] <= w) {
            pos += a[i] + 1;
        } else {
            ans++;
            pos = a[i] + 1;
        }
    }
    return ans;
}
 
int main() {
    int w, n, m;
    vector <int> a, b;
    cin >> w >> n >> m;
    a.resize(n);
    b.resize(m);
    int max1 = 0, max2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max1 = max(max1, a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        max2 = max(max2, b[i]);
    }
    int l = max1, r = w - max2 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int f1 = calc(a, mid);
        int f2 = calc(b, w - mid);
        //cerr << "!" << mid << "  " << f1 << " " << f2 << endl;
        if (f1 < f2) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << max(calc(a, l), calc(b, w - l));
    return 0;
}