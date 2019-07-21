#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b)
{
    while (a && b)
    {
        a %= b;
        swap(a, b);
    }
    return a + b;
}

signed main()
{
    int x, count = 0;
    cin >> x;
    for (int i = 1; i <= x; ++i)
    {
        if (gcd(i, x) == 1)
            count++;
    }
    cout << count << endl;
    return 0;
}
