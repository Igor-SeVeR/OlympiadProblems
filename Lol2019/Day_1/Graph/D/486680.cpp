#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

    vector<int> b, c;
    int k, d[10], md[100001], pred[100001], zn[100001];

void bfs(int v)
{
    int i, j;
    md[v] = 1;
    zn[v] = -1;
    b.push_back(v);
    while(b.size() != 0)
    {
        for(i = 0; i < b.size(); i++)
        {
            for(j = 0; j < 10; j++)
            {
                if(d[j] == 1 && md[(10 * b[i] + j) % k] == 0)
                {
                    md[(10 * b[i] + j) % k] = 1;
                    zn[(10 * b[i] + j) % k] = j;
                    pred[(10 * b[i] + j) % k] = b[i];
                    c.push_back((10 * b[i] + j) % k);
                }
            }
        }
        b.clear();
        for(i = 0; i < c.size(); i++)
            b.push_back(c[i]);
        c.clear();
    }
}

int main()
{
//freopen("multiple.in", "r", stdin);
//freopen("multiple.out", "w", stdout);
    int i, n, s = 0, z, g;
    vector <int> ans;
    char x[1001];
    for(i = 0; i < 10; i++)
        d[i] = 0;
    cin >> x >> k >> g;
    for(i = 0; i < k; i++)
        md[i] = 0;
    for(i = 0; i < g; i++)
    {
        cin >> z;
        d[z] = 1;
    }
    n = strlen(x);
    for(i = 0; i < n; i++)
    {
        s = 10 * s + (x[i] - 48);
        if(s >= k)
            s %= k;
    }
    bfs(s);
    if(md[0] == 0)
        cout << "-1";
    else
    {
        z = 0;
        while(zn[z] != -1)
        {
            ans.push_back(zn[z]);
            z = pred[z];
        }
        cout << x;
        for(i = ans.size() - 1; i > -1; i--)
            cout << ans[i];
    }
return 0;
}

