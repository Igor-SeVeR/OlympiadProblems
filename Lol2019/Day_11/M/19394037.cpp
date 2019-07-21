#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
string sm(string s1, string s2)
{
    if(s1.size() < s2.size())
    {
        swap(s1, s2);
    }
    string ans;
    int cl = 0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for(int i = 0; i < s2.size(); i++)
    {
        int a = s2[i] - '0';
        int b = s1[i] - '0';
        int c = a + b + cl;
        cl = c / 10;
        char x = c % 10 + '0';
        ans.push_back(x);
    }
    for(int i = (int)s2.size(); i < (int)s1.size(); i++)
    {
        int a = s1[i] - '0';
        int b = cl;
        int c = a + b;
        cl = c / 10;
        char x = c % 10 + '0';
        ans.push_back(x);
    }
    if(cl != 0)
    {
        ans.push_back(cl + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
signed main()
{
    int x, k;
    cin >> x >> k;
    vector<vector<string>> c(301, vector<string>(301, "0"));
    c[0][0] = "1";
    for(int i = 1; i <= 300; i++)
    {
        c[i][0] = "1";
        c[i][i] = "1";
        for(int j = 1; j < i; j++)
        {
            c[i][j] = sm(c[i - 1][j - 1], c[i - 1][j]);
        }
    }
    vector<vector<int>> c1(301, vector<int>(301));
    c1[0][0] = 1;
    for(int i = 1; i <= 300; i++)
    {
        c1[i][0] = 1;
        c1[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            c1[i][j] = c1[i - 1][j - 1] + c1[i - 1][j];
        }
    }
    x /= 5;
    cout << c[x + k][k];
}
