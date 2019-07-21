#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

void search(int x, int y, vector<vector<char>> &a, int h, int w)
{
    ans++;
    a[y][x] = '#';
    if ((x > 0) && (a[y][x - 1] == '.'))
        search(x - 1, y, a, h, w);
    if ((x < w - 1) && (a[y][x + 1] == '.'))
        search(x + 1, y, a, h, w);
    if ((y < h - 1) && (a[y + 1][x] == '.'))
        search(x, y + 1, a, h, w);
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (auto &i : a)
    {
        for (auto &j : i)
            cin >> j;
    }
    for (int i = 0; i < w; ++i)
    {
        if (a[0][i] == '.')
        {
            search(i, 0, a, h, w);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
