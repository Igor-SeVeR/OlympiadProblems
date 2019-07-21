#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int max = 1;
    for (int i = 2; i <= min(a, min(b, c)); ++i)
    {
        if ((a % i == 0) && (b % i == 0) && (c % i == 0))
            max = i;
    }
    cout << max << endl;
    return 0;
}
