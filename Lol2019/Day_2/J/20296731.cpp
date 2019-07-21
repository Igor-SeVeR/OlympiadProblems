#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    stack<int> st;
    while (cin >> c) {
        if ('0' <= c && c <= '9') {
            st.push(c-'0');
        } else if (c == '+') {
            int t2 = st.top();
            st.pop();
            int t1 = st.top();
            st.pop();
            st.push(t1+t2);
        } else if (c == '-') {
            int t2 = st.top();
            st.pop();
            int t1 = st.top();
            st.pop();
            st.push(t1 - t2);
        } else if (c == '*') {
            int t2 = st.top();
            st.pop();
            int t1 = st.top();
            st.pop();
            st.push(t1 * t2);
        }
    }
    cout << st.top();
    return 0;
}