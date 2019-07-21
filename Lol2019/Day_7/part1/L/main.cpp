#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = -n;
    while (n--)
    {
        int x;
        cin >> x;
        res += x;
    }
    cout << res << endl;
    return 0;
}
