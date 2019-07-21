#include <bits/stdc++.h>

using namespace std;

int main()
{
    string res, s;
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int n1 = n;
    for (int i = 0; i < pow(2, n1); i++)
    {
        int k = i;
        string s;
        for (int j = 0; j < n; j++)
        {
            if (k % 2 == 0)
                s = s + '0';
            else
                s = s + '1';
            k /= 2;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}
