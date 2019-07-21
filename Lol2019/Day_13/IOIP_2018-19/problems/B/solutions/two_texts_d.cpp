#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int n, w, k;
vector<int> a, b;
 
int f1(int m) {
    int ans = 1;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            return 1000000000;
        }
        if (a[i] + pos <= m) {
            pos += a[i] + 1;
        } else {
            pos = a[i] + 1;
            ans++;
        }
    }
    return ans;
}
 
int f2(int m) {
    int ans = 1;
    int pos = 0;
    for (int i = 0; i < k; i++) {
        if (b[i] > m) {
            return 1000000000;
        }
        if (b[i] + pos <= m) {
            pos += b[i] + 1;
        } else {
            pos = b[i] + 1;
            ans++;
        }
    }
    return ans;
}
 
int main() {
    //freopen("multimap.in", "r", stdin);
    //freopen("multimap.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> w >> n >> k;
    a.resize(n); b.resize(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    int l = 0;
    int r = w;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (f1(m) < f2(w - m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << min(max(f1(l), f2(w - l)), max(f1(l + 1), f2(w - l - 1)));
    return 0;
}