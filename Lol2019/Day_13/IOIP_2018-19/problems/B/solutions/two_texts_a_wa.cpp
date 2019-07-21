#include <bits/stdc++.h>
 
using namespace std;
 
int f(int w, vector<int> const &v) {
    int lines = 0;
    int left = w;
    for (int i = 0; i < (int)v.size(); i++) {
        int x = v[i];
        if (x <= left) {
            left = left - x - 1;
            if (left <= 0) {
                lines++;
                left = w;
            }
        } else {
            lines++;
            left = w;
            i--;
        }
    }
    if (left != w) {
        lines++;
    }
    return lines;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int w, n, m;
    cin >> w >> n >> m;
    vector<int> first(n), second(m);
    int firstmax = 0;
    for (auto &x : first) {
        cin >> x;
        firstmax = max(firstmax, x);
    }
    int secondmax = 0;
    for (auto &x : second) {
        cin >> x;
        secondmax = max(secondmax, x);
    }
    int l = firstmax, r = w - secondmax;
    while (l < r) {
        int mt = (l + r) / 2;
        int nl = f(mt, first), nr = f(w - mt, second);
        if (nl == nr) {
            l = r = mt;
        } else if (nl < nr) {
            r = mt - 1;
        } else {
            l = mt + 1;
        }
    }
    cout << max(f(l, first), f(w - l, second));
    return 0;
}