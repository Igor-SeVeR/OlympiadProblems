//#include "/Users/stepan_bagritsevich/Dropbox/stdc++.h"
#include <bits/stdc++.h>
 
using namespace std;

#define pb push_back
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

const int MAX_VAL = 2147483647, MIN_VAL = -2147483648;

int main() {
    int r, c;
    cin >> r >> c;
    int n = r * c;
    
    vector < int > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a.begin(), a.end());
    
    int ans = MIN_VAL;
    for (int i = 0; i < n; i += c)
        if (a[i + c - 1] - a[i] > ans)
            ans = a[i + c - 1] - a[i];
    
    cout << ans << "\n";
    return 0;
}