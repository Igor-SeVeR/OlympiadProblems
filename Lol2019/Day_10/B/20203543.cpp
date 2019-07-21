#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    double mas[100005];
    vector <double> aa, bb;
    cout << fixed << setprecision(4);
    ll n, i, j, k;
    double a, b;
    cin >> n;
    if (n == 0){
        cout << 0;
        return 0;
    }
    for (i = 0; i < n; i++){
        cin >> mas[i];
    }

    sort(mas, mas + n);

    cin >> k;
    ll i1 = 0, i2 = 0;
    for (i = 0; i < k; i++){
        cin >> a >> b;
        if (a == 1){
            aa.push_back(b);
            i1++;
        } else {
            bb.push_back(b);
            i2++;
        }
    }
    if (i1) sort(aa.begin(), aa.end());
    if (i2) sort(bb.begin(), bb.end());
    double ans = 0, cur;
    for (j = 0; j <= min(i1, n); j++){
        cur = 0;
        for (i = 1; i <= j; i ++){
            a = mas[n - i];
            b = aa[i1 - i];
            cur += a * (1 + double(b) / 100);
        }
        ll p = i2;
        for (i = j + 1; i <= n; i++){
            if (p == 0) break;
            cur += bb[p - 1] + mas[n - i];
            p--;
        }
        for (; i <= n; i++){
            cur += mas[n - i];
        }
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}
