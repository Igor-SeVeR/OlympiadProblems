#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() 
{
	int numb, x;
	cin >> numb;
	set < pair < int, int > > seter;
	set < pair < int, int > > dops;
	vector < vector < int > > tournir(numb, vector < int >(numb, 0));
	for (int i = 0; i < numb; i++) 
	{
		cin >> x;
		seter.insert({ x, i });
	}
	while ( !seter.empty() ) 
	{
		auto ykaz = *(--seter.end());
		seter.erase(ykaz);
		while ( !seter.empty() ) 
		{
			auto tec = *seter.begin();		
	        if (tec.first >= 1 && ykaz.first == 1)
			{
				ykaz.first--;
				tournir[tec.second][ykaz.second] = 1;
				tournir[ykaz.second][tec.second] = 1;
				seter.erase(tec);
				tec.first--;
				seter.insert(tec);
			}
			else if (ykaz.first >= 2)
			{
				ykaz.first -= 2;
				tournir[tec.second][ykaz.second] = 0;
				tournir[ykaz.second][tec.second] = 2;
			}
			else if (tec.first >= 2)
			{
					seter.erase(tec);
					tec.first -= 2;
					seter.insert(tec);
					tournir[tec.second][ykaz.second] = 2;
					tournir[ykaz.second][tec.second] = 0;
			}
			seter.erase(tec);
			dops.insert(tec);
		}
		seter.clear();
		seter = dops;
		dops.clear();
	}
	for (int i = 0; i < numb; i++) 
	{
		for (int j = 0; j < numb; j++) 
		{
			cout << tournir[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}