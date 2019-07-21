#include <iostream>
#include <cmath>

using namespace std;
int vp, vf;
double a;

double f(double x) {
	return sqrt(x * x + (1 - a) * (1 - a)) / vp + sqrt(a * a + (1 - x) * (1 - x)) / vf;
}

int main() {
	cin >> vp >> vf >> a;
	double L = 0, R = 1, EPS = 0.0000000001;
	while (R - L > EPS) {
            double l = L + (R - L) / 3, r = R - (R - L) / 3;
            if (f(l) <= f(r))
                R = r;
            else
                L = l;
	}
        cout << R;
	return 0;
}
