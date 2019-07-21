#include<iostream>
#include<vector>

using namespace std;

int n, k;
vector<int> v(0);

int a(int m){
    int pos = v[0];
    int ans = 1;
    for (int i = 1; i < n; ++i){
        if (v[i] - pos >= m){
            ++ans;
            pos = v[i];
        }
    }
    return ans;
}

int main(){
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int l = 0, r = 1000000009;
    while (l != r - 1){
        int m = (l + r) / 2;
        if (a(m) >= k)
            l = m;
        else
            r = m;
    }
    cout << l;
}
