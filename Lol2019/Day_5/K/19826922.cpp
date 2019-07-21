#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector <pair<int, pair<int, int>>> events;
    vector <int> balance(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int h, m, city;
        char c;
        //отправление
        cin >> city >> h >> c >> m;
        int time1 = 60 * h + m;
        events.push_back({time1, {1, city}});
        balance[city]--;
        //прибытие
        cin >> city >> h >> c >> m;
        int time2 = 60 * h + m;
        if (time2 <= time1)
        {
            ans++;
        }
        events.push_back({time2, {0, city}});
        balance[city]++;
    }
    for (int i = 1; i <= n; i++)
        if (balance[i] != 0)
        {
            cout << - 1;
            return 0;
        }
    sort(events.begin(), events.end());

    for (auto ev : events)
    {
        int city = ev.second.second;
        int type = ev.second.first;
        //cout << ev.first << ' ' << city << ' ' << type << endl;
        if (type == 0)
        {
            balance[city]++;
        }
        else
        {
            if (balance[city] == 0)
                ans++;
            else
                balance[city]--;
        }
    }
    cout << ans;
    return 0;
}
