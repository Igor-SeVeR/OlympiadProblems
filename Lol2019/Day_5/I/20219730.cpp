#include <iostream>

using namespace std;

int
main()
{
  int n, k, x, rr, ll;
  cin >> n;
  int intArray[n];
  for (int i = 0; i < n; i++) {
    cin >> intArray[i];
  }
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> x;
    int m, l = 0, r = n - 1;

    while (l != r) {
      m = (l + r) / 2;
      if (intArray[m] < x)
        l = m + 1;
      else
        r = m;
    }

    if (intArray[l] == x)
      ll = l + 1;
    else
      ll = 0;

    l = 0;
    r = n - 1;
    while (l < r - 1) {
      m = (l + r) / 2;
      if (intArray[m] <= x)
        l = m;
      else
        r = m - 1;
    }


  if (intArray[r] == x)
    rr = r + 2;
  else if (intArray[l] == x)
    rr = l + 2;
  else
    rr = 0;

  cout << rr - ll << '\n';
}
return 0;
}