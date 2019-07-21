#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long ans = 0;
    string s;
    vector <long long> cur = {0};
    while (getline(cin, s)) {
        if (s[0] == 'p') {
            int i = 6;
            int val = 0;
            while (i < s.size()) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            cur.push_back(cur[cur.size() - 1] + val);
            ans += val;
        } else {
            int i = 5;
            int num = 0, cnt = 0;
            while (s[i] != ' ') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i++;
            while (i < s.size()) {
                cnt = cnt * 10 + (s[i] - '0');
                i++;
            }
            cur.push_back(cur[cur.size() - 1]);
            ans += cnt * (cur[cur.size() - 1] - cur[num - 1]);
        }
    }
    cout << ans;
    return 0;
}
