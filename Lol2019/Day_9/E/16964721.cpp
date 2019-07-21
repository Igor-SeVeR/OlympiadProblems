#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, f; cin >> s >> f;
    int ans = (f - s + 12) % 12;
    if (ans == 0) cout << 12;
    else cout << ans;
    return 0;
}
