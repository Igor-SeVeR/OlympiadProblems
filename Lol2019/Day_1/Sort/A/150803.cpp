#include <cstdio>
#include <algorithm>
using namespace std;

class Box
{
 public:
        int a, b, c;
	Box(){}
	void scan(void)
	{
                scanf("%d%d%d", &a, &b, &c);
	}
};
int V(const Box& a)
{
        return a.a * a.b * a.c;
}
bool operator<(const Box& a, const Box& b)
{
        return V(a) < V(b);
}
void print(Box &a)
{
        printf("%d %d %d\n", a.a, a.b, a.c);
}
const int MAXN = 100 + 10;
Box a[MAXN];
int main()
{
	int n;
        scanf("%d", &n);
	int i;
        for (i = 0; i < n; i++)
		a[i].scan();
        sort(a, a + n);
        for (i = 0; i < n; i++)
		print(a[i]);
	
	return 0;
}
