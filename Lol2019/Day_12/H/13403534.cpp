#include <bits/stdc++.h>

using namespace std;

signed main()
{
    int n;
    cin >> n;
    long double l = 0, r = 1e9;
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        long double l1 = v, r1 = v + 1;
        l1 /= (i + 1);
        r1 /= (i + 1);
        l = max(l, l1);
        r = min(r, r1);
    }
    if (r - l < -1e-8)
        cout << "No solution" << endl;
    else
        cout << fixed << setprecision(6) << l << " " << r << endl;
}