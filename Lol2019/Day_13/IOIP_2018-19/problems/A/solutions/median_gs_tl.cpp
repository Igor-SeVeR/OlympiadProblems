#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        nth_element(a.begin(), a.begin() + a.size() / 2, a.end());
        int med = a[a.size() / 2];
        cout << med << ' ';
        a.erase(a.begin() + a.size() / 2);
    }
    cout << endl;
    return 0;
}