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
    int a, b, c;
    cin >> a >> b >> c;
    cout << gcd(gcd(a, b), c) << endl;
    return 0;
}
