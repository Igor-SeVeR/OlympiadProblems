#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int p = (b + c - 1) / c;
    int z = (d + a - 1) / a;
    if (p < z){
        cout << "LOSE";
    }
    else if (z < p){
        cout << "WIN";
    }
    else{
        cout << "DRAW";
    }
}
