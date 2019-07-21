#include "testlib.h"
using namespace std;

const int MAXN[] = {
    3000,     // 0
    7,        // 1
    15,       // 2
    80,       // 3
    400,      // 4
    3000,     // 5
};

void dfs(int u, vector<vector<int>>& gr, vector<bool>& used) {
  used[u] = true;
  for (int v : gr[u]) {
    if (!used[v]) {
      dfs(v, gr, used);
    }
  }
}

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int grp = validator.group().empty() ? 0 : stoi(validator.group());
  int n = inf.readInt(1, MAXN[grp], "n");
  inf.readEoln();
  vector<vector<int>> gr(n);
  for (int i = 0; i < n - 1; ++i) {
    int a = inf.readInt(1, n, format("a[%d]", i + 1));
    inf.readSpace();
    int b = inf.readInt(1, n, format("b[%d]", i + 1));
    inf.readEoln();
    gr[a - 1].push_back(b - 1);
    gr[b - 1].push_back(a - 1);
  }

  vector<bool> used(n);
  dfs(0, gr, used);

  for (int i = 0; i < n; ++i) {
    ensuref(used[i], "%d-th vertex is not connected with first", i + 1);
  }

  inf.readEof();
}
