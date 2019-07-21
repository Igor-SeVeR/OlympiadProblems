#include<bits/stdc++.h>
using namespace std;
long long a;
long long l, r, ans, mid;

int main(){
    cin >> a;
    r = a - 1;
    while (r != l)
    {
        mid = (l + r) / 2;
        ans++;
        r = mid;
    }
    cout << ans << endl;
}
