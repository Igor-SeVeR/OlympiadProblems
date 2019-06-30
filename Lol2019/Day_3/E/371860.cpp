#include <iostream>
#define N 1001

using namespace std;

int main()
{
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
    int i, j, x, d[N][N];
    string a, b;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    d[0][0] = 0;
    for (i = 1; i < a.length(); i++)
        d[i][0] = i;
    for (j = 1; j < b.length(); j++)
        d[0][j] = j;
    for (i = 1; i < a.length(); i++)
        for (j = 1; j < b.length(); j++)
        {
            x = 1;
            if (a[i] == b[j])
                x = 0;
            d[i][j] = min(d[i - 1][j - 1] + x, min(d[i][j - 1], d[i - 1][j]) + 1);
        }
    cout << d[a.length() - 1][b.length() - 1];
return 0;
}
