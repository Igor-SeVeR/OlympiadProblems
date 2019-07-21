#include "testlib.h"
#include <string>
using namespace std;

const int MAXN[3] = {1000, 1000, 100000};
const int MAXX = int(1e9);

int main(int argc, char * argv[]) 
{
    registerValidation(argc, argv);
    int group = 0;
    group = atoi(validator.group().c_str());
    int n = inf.readInt(1, MAXN[group], "n");
    inf.readEoln();
    for (int i = 0; i < n; i++)
    {
        inf.readInt(1, MAXX, format("a[%d]", i + 1));
        if (i < n - 1)
            inf.readSpace();
        else
            inf.readEoln();
    }
    inf.readEof();
    return 0;
}