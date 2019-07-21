#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int l, r, cnt = 1;
    l = r = a[0].second;
    for (int i = 1; i < n; ++i)
    {
        if (a[i].second < l)
            l = a[i].second;
        else if (a[i].second > r)
            r = a[i].second;
        if (r - l == i)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
