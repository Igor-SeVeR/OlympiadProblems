#include <bits/stdc++.h>

using namespace std;

int64_t inf = 1000 * 1000 * 1000;
int64_t inf64 = inf * inf;
int64_t nll = 0;

#define ll long long
#define se second
#define fi first
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int64_t n;
    cin >> n;
    set<pair<int32_t, int32_t>> q;
    vector <int32_t> ans(n, -1);
    ans[0] = 1;
    int64_t x;
    cin >> x;
    q.insert({x, 1});
    for (int32_t i = 1; i < n; ++i)
    {
        auto r = *q.begin();
        int64_t t;
        cin >> t;
        if (t <= r.fi)
        {
            q.insert({t, q.size() + 1});
            ans[i] = q.size();
            //cout << "!" << endl;
        }
        else
        {
            auto it = q.upper_bound({t, -1});
            --it;
            auto t1 = *it;
            ans[i] = t1.se;
            q.insert({t, t1.se});
            q.erase(t1);
            //cout << "?" << endl;
        }
    }
    cout << q.size() << endl;
    for (auto &c : ans) cout << c << " ";
}
/*
7
6 9 2 44 1 43 8
4
1 5 3
2 6 4
5 7 2
3 6 1
*/
