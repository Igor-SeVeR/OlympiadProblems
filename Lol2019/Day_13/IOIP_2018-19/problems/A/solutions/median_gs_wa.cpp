#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int i = n / 2;
    int j = n / 2 + 1;
    //if (n % 2 == 1)
    //    cout << a[j++ - 1] << ' ';
    for (int k = 0; k < n / 2; k++)
        cout << a[i-- - 1] << ' ' << a[j++ - 1] << ' ';
    cout << endl; 
    return 0;
}