#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
using namespace std;

ll n, k, x, y;
ll pc, bc;

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> k >> x >> y;
    pc = n*y + n/k * (x-y);
    bc = (k-1) * y + x;

    int q;
    cin >> q;
    while (q--)
    {
        ll c;
        cin >> c;
        c = (c - 1) % pc;
        ll ans = 0;
        ans = c / bc * k;
        c %= bc;
        if (c < bc - x)
            ans += c / y;
        else
            ans += k - 1;
        cout << ans + 1 << "\n";
    }

    return 0;
}
