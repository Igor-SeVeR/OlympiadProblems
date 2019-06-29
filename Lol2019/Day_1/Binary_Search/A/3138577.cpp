#include <iostream>
#include <cmath>

using namespace std;

bool f(double c, double x)
{
    return (x * x + sqrt(x) - c > 0.);
}

int main()
{
    double c;
    cin >> c;
    double p = 1.;
    double q = 1e10;
    double EPS = 1e-9;
    while (q - p > EPS)
    {
        double m = (p + q) / 2.;
        if (f(c, m))
        {
            q = m;
        }
        else
        {
            p = m;
        }
    }
    cout.precision(20);
    cout << fixed;
    cout << (p + q) / 2. << endl;
    return 0;
}
