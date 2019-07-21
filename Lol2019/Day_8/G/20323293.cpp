#include <bits/stdc++.h>

using namespace std;

int n, m, k = 1, a, b, u[20001], ans[20001];
vector <int> g[20001], gr[20001];
vector <int> v;

void dfs(int i)
{
    for (int j = 0 ; j < g[i].size() ; j++)
    {
        if (u[g[i][j]] == 0)
        {
            u[g[i][j]] = 1;
            dfs(g[i][j]);
        }
    }
    v.push_back(i);
}

void f(int i)
{
    for (int j = 0 ; j < gr[i].size() ; j++)
    {
        if (ans[gr[i][j]] == 0)
        {
            ans[gr[i][j]] = k;
            f(gr[i][j]);
        }
    }
}

int main()
{
    iostream::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    for (int i = 1 ; i <= n ; i++)
    {
        if (u[i] == 0)
        {
            u[i] = 1;
            dfs(i);
        }
    }
    reverse(v.begin(), v.end());
    for (int i = 0 ; i < v.size() ; i++)
    {
        auto x = v[i];
        if (ans[x] != 0)
            continue;
        ans[x] = k;
        f(x);
        k++;
    }
    cout << k - 1 << endl;
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    return 0;
}
