#include "testlib.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int p = atoi(argv[3]);
    cout << n << ' ' << m << ' ' << p << '\n';
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int x = rnd.next(0, p - 1);
        cout << x;
        if (j != m - 1)
        {
          cout << ' ';
        }
        else
        {
          cout << '\n';
        }
      }
    }
}

