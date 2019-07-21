#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int x;
    cin >> x;
    int result = x;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
                x /= i;
            result -= result / i;
        }
    }
    if (x > 1)
        result -= result / x;
    cout << result << endl;
    return 0;
}
