#include <iostream>
using namespace std;

int main() {
        long n;
        cin >> n;
        long answers[n];
        answers[0] = 0;
        const long max = n;
        for (long i = 1; i <= max; i++)
        {
                long up = ((i + 1) * i) / 2;

                long a1 = (i + 1) % 2;
                long aN = i - 1;
                long num = (i + 1) / 2;
                long down = ((a1 + aN) / 2) * num;

                answers[i] = up + down + answers[i - 1];
        }
        cout << answers[n] << endl;
}
