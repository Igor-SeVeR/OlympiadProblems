#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int cur_test = -1;
const int GROUPS_CNT = 2;
const int MAXN[3] = {1, int(1e3), int(1e5)};
const int MAXX = int(1e9);

void write_test(vector<int> test) 
{
    startTest(cur_test++);
    cerr << cur_test << endl;
    cout << test.size() << endl;
    for (int i = 0; i < test.size() - 1; i++)
        cout << test[i] << ' ';
    cout << test.back() << endl;
}


void gen_rand(int n, int maxn)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rnd.next(1, maxn);
    write_test(v);
}

void gen_equal(int n, int x)
{
    vector<int> v(n, x);
    write_test(v);
}

int med(int x)
{
    return rnd.next(max(x / 2, 1), x);
}

int main(int argc, char * argv[]) 
{
    registerGen(argc, argv, 1);
    cur_test = atoi(argv[1]);
    gen_rand(1, 4);
    for (int g = 1; g <= GROUPS_CNT; g++)
    {
        for (int i = MAXN[g - 1] * 10; i <= MAXN[g]; i *= 10)
        {
            int n;
            n = med(i);
            gen_rand(n -  n % 2, i);
            n = med(i);
            gen_rand(n - (n + 1)% 2, i);
            n = med(i);
            gen_equal(n, rnd.next(1, i));
        }
        gen_rand(MAXN[g] - 1, MAXX);
        gen_rand(MAXN[g], MAXX);
        gen_equal(MAXN[g], MAXX);
        cerr << "GROUP ENDS" << endl;
    }
    return 0;
}