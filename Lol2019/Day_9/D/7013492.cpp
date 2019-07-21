#include<iostream>
#include<algorithm>

using namespace std;

double tern(double xc, double yc, double x1, double y1, double x2, double y2)
{
    double lx = x1;
    double ly = y1;
    double rx = xc;
    double ry = yc;
    double m1x, m2x, m1y, m2y, s1, s2;

    while (rx - lx > 0.00000000001)
    {
        m1x = (rx + 2 * lx) / 3;
        m2x = (2 * rx + lx) / 3;
        m1y = (ry + 2 * ly) / 3;
        m2y = (2 * ry + ly) / 3;
        s1 = m1y * (xc - m1x);
        s2 = m2y * (xc - m2x);

        if (s1 > s2)
        {
            rx = m2x;
            ry = m2y;
        }
        else
        {
            lx = m1x;
            ly = m1y;
        }
    }
    return max(s1, s2) * 2;
}

int main()
{
    double xc, yc, x1, y1, x2, y2;
    cin >> xc >> yc >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }


    if (y1 < y2)
    {
        double c = y2 - y1;
        y2 -= c;
        y1 += c;
        x1 += c;
        x2 += c;
    }

    double res = tern(xc, yc, x1, y1, x2, y2);
    cout.precision(10);
    cout << fixed << res;
    return 0;
}
