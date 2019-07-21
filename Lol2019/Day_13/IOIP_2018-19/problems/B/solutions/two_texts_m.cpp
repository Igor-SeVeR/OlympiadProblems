// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
#define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl;
#define fastIO std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define NAME "Problem Name"
 
typedef long long ll;
typedef long double ld;
 
std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
 
const double PI = atan2(0., -1.);
const int INF = 0x3f3f3f3f;
const int N = 100100;
 
int a[N], b[N];
 
int main(void) {
    // #ifdef ONLINE_JUDGE
    //  freopen(NAME".in", "r", stdin);
    //  freopen(NAME".out", "w", stdout);
    // #endif
 
    int w, n, m;
    scanf("%d%d%d", &w, &n, &m);
 
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        mx1 = std::max(mx1, a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        mx2 = std::max(mx2, b[i]);
    }
 
    int l = mx1 - 1, r = w - mx2 + 1;
    int ans = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int cnt1 = 1, cnt2 = 1;
        int col = 0;
        for (int i = 0; i < n; ++i) {
            if (col + a[i] > mid) {
                ++cnt1;
                col = a[i] + 1;
            } else {
                col += a[i] + 1;
            }
        }
        col = 0;
        for (int i = 0; i < m; ++i) {
            if (col + b[i] > w - mid) {
                ++cnt2;
                col = b[i] + 1;
            } else {
                col += b[i] + 1;
            }
        }
 
        int curAns = std::max(cnt1, cnt2);
        ans = std::min(ans, curAns);
        if (cnt1 > cnt2) {
            l = mid;
        } else {
            r = mid;
        }
    }
 
    printf("%d\n", ans);
 
    return 0;
}