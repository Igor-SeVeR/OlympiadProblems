#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

// ========================================================================= //

const int N = 3033;

int n;
int cnk[N][N];
vector<ipair> e[N];

vector<int> dfs(int v, int p = -1) {
    vector<int> d1 = {1};
    for (ipair nvp : e[v]) {
        if (nvp.X == p)
            continue;
        vector<int> nd = dfs(nvp.X, v);
        vector<int> nds = {0};
        for (int x : nd)
            nds.push_back((nds.back() + x) % MOD);
        vector<int> d2(sz(d1) + sz(nd), 0);

        for (int x1 = 0; x1 < sz(d1); ++x1)
            for (int cnt1 = 0; cnt1 <= sz(nd); ++cnt1) {
                int x2 = x1 + cnt1;
                int val = 1;
                val = (1LL * val * cnk[x2][cnt1]) % MOD;
                val = (1LL * val * cnk[sz(d2) - 1 - x2][sz(nd) - cnt1]) % MOD;
                val = (1LL * val * d1[x1]) % MOD;
                if (nvp.Y)
                    val = (1LL * val * nds[cnt1]) % MOD;
                else
                    val = (1LL * val * ((nds.back() - nds[cnt1] + MOD) % MOD)) % MOD;
                d2[x2] = (d2[x2] + val) % MOD;
            }

        swap(d1, d2);
    }
    return d1;
}

int main() {
    for (int i = 0; i < N; ++i) {
        cnk[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            cnk[i][j] = (cnk[i-1][j-1] + cnk[i-1][j]) % MOD;
    }

    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        e[x].push_back({y, 0});
        e[y].push_back({x, 1});
    }
    
    vector<int> res = dfs(0);
    int a = 0;
    for (int x : res)
        a = (a + x) % MOD;
    cout << a << "\n";

    return 0;
}
