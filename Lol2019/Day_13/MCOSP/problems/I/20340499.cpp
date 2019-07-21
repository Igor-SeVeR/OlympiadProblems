#include <bits/stdc++.h>

using namespace std;

using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;

const double esp = 1e-18;

int main()
{
    string s;
    getline(cin, s);
    string a = "";
    for(int i = 0; i < s.size(); i++) if(s[i] != '-') a += s[i];
    int cnt = 0;
    for(int i = 0; i < a.size() - 1; i++){
        if(a[i] == ':' || a[i] == ';')
            if(a[i + 1] == ')' || a[i + 1] == '(' || a[i + 1] == ']' || a[i + 1] == '[') cnt++;
    }
    cout << cnt;
    return 0;
}