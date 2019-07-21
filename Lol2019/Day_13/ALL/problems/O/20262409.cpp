#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	vector<int> win(n);
	for(int i=0;i<n;i++){
		scanf("%d", &win[i]);
	}
	int minSpeed, maxSpeed, speedDec;
	scanf("%d %d %d", &minSpeed, &maxSpeed, &speedDec);
	int minShift = (minSpeed - 1) / speedDec;
	int toVisit = min(n, (maxSpeed - 1) / speedDec + 1 - minShift);
	assert(toVisit > 0);
	int max1 = 0;
	for(int di=-1;di<=1;di+=2){
		int pos = di * minShift;
		pos %= n;
		pos += n;
		pos %= n;
		for(int i=0;i < toVisit; i++){
			max1 = max(max1, win[pos]);
		pos += di;
		pos %= n;
		pos += n;
		pos %= n;			
		}
	}
	assert(max1 > 0);
	printf("%d", max1);
	return 0;
}

