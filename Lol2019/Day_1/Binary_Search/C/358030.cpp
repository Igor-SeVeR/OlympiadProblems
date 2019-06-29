#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair
{
	int num;
	int value;
	Pair(){}
	Pair(int Num, int Value)
	{
		num = Num;
		value = Value;
	}
};
bool operator < (const Pair &a, const Pair &b)
{
        return a.value < b.value;
}
vector<Pair> a, b;
int n, m, value;
void input()
{
        scanf("%d%d", &m, &n);
	a.resize(m);
	b.resize(n);
        for (int i = 0; i < m; i++)
	{
                scanf("%d", &value);
                a[i] = Pair(i + 1, value);
	}
        for (int i = 0; i < n; i++)
	{
                scanf("%d", &value);
                b[i] = Pair(i + 1, value);
	}
}
struct answer
{
	int olen;
	int elf1;
	int elf2;
	answer(){}
	answer(int Olen, int Elf1, int Elf2)
	{
		olen = Olen;
		elf1 = Elf1;
		elf2 = Elf2;
	}
};
vector<answer> res;
void solve()
{
	//a - олени
	//b - эльфы
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
	int i = 0; //меньший эльф
        int j = b.size() / 2; //больший эльф
	int k = 0; //олень

        res.reserve(b.size() / 2);
        while (k < m && j < n)
	{
		// поиск первого k-ого оленя больше младшего i-ого эльфа
                while (k < m && a[k].value <= b[i].value) k++;
		// поиск первого j-ого эльфа большего k-ого оленя
                while (j < n && b[j].value <= a[k].value) j++;
                if (k != m && j != n)
                        res.push_back(answer(a[k].num, b[i].num, b[j].num));
		i++;
		j++;
		k++;	
	}
        printf("%d\n", res.size());
        for (int i = 0; i < res.size(); i++)
                printf("%d %d %d\n", res[i].olen, res[i].elf1, res[i].elf2);
}
int main()
{
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	input();
	solve();
	return 0;
}
