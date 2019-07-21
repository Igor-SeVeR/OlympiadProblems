#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 1000000, "m");
    inf.readSpace();
    int p = inf.readInt(1, 1000000, "p");
    inf.readEoln();
    ensuref(n * (long long) m <= 1000000, "n x m is too big");
    if (validator.group() == "1") ensuref(n * m <= 3000, "n x m is too big for group 1");
    if (validator.group() == "2") ensuref(n <= 300 && m <= 300, "n or m are too big for group 2");
    if (validator.group() == "3") ensuref(n == 1 || m == 1, "n != 1 and m != 1 in group 3");
    if (validator.group() == "4") ensuref(p <= 5000, "p is too big in group 4");
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int x = inf.readInt(0, p - 1, "a_{i, j}");
        if (j != m - 1)
          inf.readSpace();
        else
          inf.readEoln();
      }
    }
    inf.readEof();
}
