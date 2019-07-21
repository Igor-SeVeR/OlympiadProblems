#include <bits/stdc++.h>

using namespace std;

bool compa(pair <string, string> a, pair <string, string> b) {
    vector <string> comp = {"A", "AB", "ABC", "BC", "B"};
    for (int i = 0; i < 5; i++) {
        if (comp[i] == b.first) return false;
        if (comp[i] == a.first) return true;
    }
}

bool compc(pair <string, string> a, pair <string, string> b) {
    vector <string> comp = {"C", "BC", "ABC", "AB", "B"};
    for (int i = 0; i < 5; i++) {
        if (comp[i] == b.first) return false;
        if (comp[i] == a.first) return true;
    }
}

int main()
{
    int n; cin >> n;
    vector <pair <string, string> > data(n);
    bool abc = false, a = false, b = false, c = false;
    for (int i = 0; i < n; i++) {
        string code, name;
        cin >> code >> name;
        data[i] = make_pair(code, name);
        if (code == "ABC") abc = true;
        else if (code == "A") a = true;
        else if (code == "B") b = true;
        else if (code == "C") c = true;
    }
    if (abc && a && b && c) {
        cout << "Impossible";
        return 0;
    }
    if (abc) {
        if (b) {
            if (a) {
                sort(data.begin(), data.end(), compa);
            } else {
                sort(data.begin(), data.end(), compc);
            }
            for (auto task : data) {
                cout << task.first << " " << task.second << endl;
            }
        } else {
            sort(data.begin(), data.end());
            for (auto task : data) {
                cout << task.first << " " << task.second << endl;
            }
        }
    } else {
        sort(data.begin(), data.end());
        for (auto task : data) {
            cout << task.first << " " << task.second << endl;
        }
    }
    return 0;
}
