#define EJUDGE

#include "testlib.h"

#include <algorithm>

using namespace std;

const double eps = 1.1e-6;
const int maxN = 100000;

int n, v, cx[maxN], cv[maxN];
bool need[maxN];

double readAns( TResult err ) {
  double t = 0.0, answer = 0.0, xans;
  xans = ans.readReal();
  int k = ans.readInt();
  for (int i = 0; i < n; i++) {
    need[i] = true;
  }
  for (int i = 0; i < k; i++) {
    int id = ans.readInt(1, n) - 1;
    double pos = ans.readReal();
    if (pos < 0) {
      quitf(err, "Position must be non-negative");
    }
    need[id] = false;
    double xx = cx[id] - t * cv[id];
    if (xx < pos) {
      quitf(err, "Person %d is already in place", id + 1);
    }
    t += max(pos / v, (xx - pos) / cv[id]) + pos / v;
    answer = max(answer, t);
  }
  for (int i = 0; i < n; i++) {
    if (need[i]) {
      answer = max(answer, (double)cx[i] / cv[i]);
    }
  }
  if (fabs(xans - answer) > eps) {
    quitf(err, "Promised %.9lf, got %.9lf", xans, answer);
  }
  return xans;
}

double readOuf( TResult err ) {
  double t = 0.0, ans = 0.0, xans;
  xans = ouf.readReal();
  int k = ouf.readInt();
  for (int i = 0; i < n; i++) {
    need[i] = true;
  }
  for (int i = 0; i < k; i++) {
    int id = ouf.readInt(1, n) - 1;
    double pos = ouf.readReal();
    if (pos < 0) {
      quitf(err, "Position must be non-negative");
    }
    need[id] = false;
    double xx = cx[id] - t * cv[id];
    if (xx < pos) {
      quitf(err, "Person %d is already in place", id + 1);
    }
    t += max(pos / v, (xx - pos) / cv[id]) + pos / v;
    ans = max(ans, t);
  }
  for (int i = 0; i < n; i++) {
    if (need[i]) {
      ans = max(ans, (double)cx[i] / cv[i]);
    }
  }
  if (fabs(xans - ans) > eps) {
    quitf(err, "Promised %.9lf, got %.9lf", xans, ans);
  }
  return xans;
}

int main( int argc, char *argv[] ) {
  registerTestlibCmd(argc, argv);
  n = inf.readInt();
  v = inf.readInt();
  for (int i = 0; i < n; i++) {
    cx[i] = inf.readInt();
    cv[i] = inf.readInt();
  }
  double ja = readAns(_fail);
  double pa = readOuf(_wa);
  if (ja > pa + eps) {
    quitf(_fail, "Contestant has a better solution: %.9lf instead of %.9lf", pa, ja);
  } else if (pa > ja + eps) {
    quitf(_wa, "Jury has a better solution: %.9lf instead of %.9lf", ja, pa);
  } else {
    quitf(_ok, "%.9lf", ja);
  }
  return -1;
}
