#include <bits/stdc++.h>

using namespace std;

const double INF = 1000000;
const double kirienko_bog = 1001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.precision(15);
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    double len_f = abs(x1 - x2) + abs(y1 - y2);
    double len_s = abs(x3 - x4) + abs(y3 - y4);
    double x_ans = INF, y_ans = INF;
    if ((x1 == x3 && x3 == x2 && x2 == x4) || (y1 == y3 && y3 == y2 && y2 == y4)) {
        if (len_f == len_s) {
            double ans = 1 / len_f;
            if (y1 == y3) {
                x_ans = kirienko_bog;
                y_ans = y1 + ans;
            } else {
                x_ans = x1 + ans;
                y_ans = kirienko_bog;
            }
        }
    } else if (x1 == x2 && x3 == x4) {
        double dif = abs(x3 - x2);
        double h1 = len_f / (len_f + len_s);
        double h2 = len_s / (len_f + len_s);
        double p = dif * h1;
        if (p * len_f >= 0.1) {
            if (x3 - x2 > 0) {
                x_ans = x3 - p;
                y_ans = kirienko_bog;
            } else {
                x_ans = x3 + p;
                y_ans = kirienko_bog;
            }
        }
    } else if (y1 == y2 && y3 == y4) {
        double dif = abs(y3 - y2);
        double h1 = len_f / (len_f + len_s);
        double p = dif * h1;
        if (p * len_f >= 0.1) {
            if (y3 - y2 > 0) {
                x_ans = kirienko_bog;
                y_ans = y3 - p;
            } else {
                x_ans = kirienko_bog;
                y_ans = y3 + p;
            }
        }
    } else {
        double h1 = 1 / len_f;
        double h2 = 1 / len_s;
        if (x1 == x2) {
            x_ans = x1 + h1;
            y_ans = y3 + h2;
        } else {
            x_ans = x3 + h2;
            y_ans = y1 + h1;
        }
    }
    if (abs(x_ans) <= 5000 && abs(y_ans) <= 5000) {
        cout << "YES" << endl;
        cout << x_ans << " " << y_ans;
    } else
        cout << "NO";
    return 0;
}
