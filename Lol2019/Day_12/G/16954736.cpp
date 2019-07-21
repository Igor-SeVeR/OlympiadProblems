#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;
    vector <pair <string, string> > a;
    for (int i = 0; i < n; i++) {
        string name, res;
        cin >> name >> res;
        a.push_back({name, res});
    }
    for (int i = n - 1; i >= 0; i--) {
        int sum = 0;
        for (int j = 0; j < a[i].second.size(); j++)
            if (a[i].second[j] == '+')
                sum++;
        if (sum > k) {
            cout << "Impossible";
            return 0;
        }
        int now = 0;
        while (sum != k && now < a[i].second.size()) {
            if (a[i].second[now] == '-') {
                a[i].second[now] = '+';
                sum++;
            }
            now++;
        }
        if (i > 0 && a[i].first > a[i - 1].first) k--;
    }
    cout << "Possible" << endl;
    for (int i = n - 1; i >= 0; i--)
        cout << a[i].first << " " << a[i].second << endl;
}
