#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Rectangle {
  int xLeft, yLeft, xRight, yRight;
};

vector<int> xSmall, ySmall;
vector<Rectangle> big;
int n;
ull S = 0;

void read() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) {
      swap(x2, x1);
    }
    if (y1 > y2) {
      swap(y1, y2);
    }
    Rectangle tmp;
    tmp.xLeft = x1;
    tmp.yLeft = y1;
    tmp.xRight = x2;
    tmp.yRight = y2;
    big.push_back(tmp);
    xSmall.push_back(x1);
    xSmall.push_back(x2);
    ySmall.push_back(y1);
    ySmall.push_back(y2);
  }
}

void solve() {
  for (int i = 0; i < xSmall.size() - 1; i++) { //x
    for (int j = 0; j < ySmall.size() - 1; j++) { //y
      int x0 = xSmall[i], y0 = ySmall[j];
      for (int k = 0; k < n; k++) { //Rectangles
        if ((big[k].xLeft <= x0 && big[k].yLeft <= y0) && (x0 < big[k].xRight && y0 < big[k].yRight)) {
          S += (xSmall[i+1] - xSmall[i]) * (ull)(ySmall[j+1] - ySmall[j]);
          break;
        }
      }
    }
  }
}

int main() {
  read();
  sort(xSmall.begin(), xSmall.end());
  sort(ySmall.begin(), ySmall.end());
  xSmall.erase(unique(xSmall.begin(), xSmall.end()), xSmall.end());
  ySmall.erase(unique(ySmall.begin(), ySmall.end()), ySmall.end());
  solve();
  cout << S << endl;
  return 0;
}
