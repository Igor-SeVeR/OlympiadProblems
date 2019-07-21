#include <bits/stdc++.h>

int lie(const std::vector<int> &a, int wm) {
    if (wm < *std::max_element(a.begin(), a.end())) {
        return INT_MAX;
    }
    int cur = 0;
    int linesL = 1;
    for (int i = 0; i < (int)a.size(); i++) {
        if (cur + a[i] > wm) {
            linesL++;
            cur = a[i] + 1;
        } else {
            cur += a[i] + 1;
        }
    }
    return linesL;
}

bool can(const std::vector<int> &a,
         const std::vector<int> &b,
         int w, int length) {
    int wl = 1, wr = w;
    while (wl < wr - 1) {
        int wm = (wl + wr) / 2;
        int linesL = lie(a, wm);
        int linesR = lie(b, w - wm);
        int lines = std::max(linesL, linesR);
        if (lines <= length) {
            //std::cerr << length << ' ' << wm << ' ' << 1 << '\n';
            return true;
        }
        if (linesL > length && linesR > length) {
            //std::cerr << length << ' ' << wm << ' ' << 0 << '\n';
            return false;
        }
        if (linesL > length) {
            wl = wm;
        } else {
            wr = wm;
        }
    }
    int linesL = lie(a, wl);
    int linesR = lie(b, w - wl);
    int lines = std::max(linesL, linesR);
    //std::cerr << w << ' ' << wl << '\n';
    return (lines <= length);
}

int main() {
    int w, n, m;
    std::cin >> w >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    int l = 0, r = std::max(n, m) + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        //std::cerr << m << '\n';
        if (!can(a, b, w, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << r << '\n';
}
