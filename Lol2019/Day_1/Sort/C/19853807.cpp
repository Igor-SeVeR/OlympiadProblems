#include <bits/stdc++.h>

using namespace std;
bool comp(pair <int, int> x, pair<int, int> y)
{
    return x.first > y.first;
}
int main()
{
    int n;
    cin >> n;
    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector <pair <int, int> > b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].first;
        b[i].second = i + 1;
    }
    sort(b.begin(), b.end(), comp);
    int ot[n];
    for (int i = 0; i < n; i++)
        ot[a[i].second] = b[i].second;
    for (int i = 0; i < n; i++)
        cout << ot[i] << " ";
}
