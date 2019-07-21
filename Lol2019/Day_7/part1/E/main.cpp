#include <bits/stdc++.h>
using namespace std;

#define int long long

int toDec(int n, int k)
{
    int x = 0, power = 1;
    while (n > 0)
    {
        x += (n % 10) * power;
        power *= k;
        n /= 10;
    }
    return x;
}

int fromDec(int n, int k)
{
    string x = "";
    while (n > 0)
    {
        x = to_string(n % k) + x;
        n /= k;
    }
    if (x == "")
        return 0;
    return stoi(x);
}

signed main()
{
    int n;
    cin >> n;
    n = toDec(n, 7);
    n = fromDec(n, 9);
    cout << n << endl;
}
