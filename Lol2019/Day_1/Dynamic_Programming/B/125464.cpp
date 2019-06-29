#include <stdio.h>
#define MIN(t, m) t > m ? m : t


int mas[250][250];
char dp[250][250];
int i, j, k, n;
int main() {
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf("%1d", &mas[i][j]);
			if(i - 1 < 0)
				mas[i][j] += mas[i][j - 1];
			else
				if(j - 1 < 0)
					mas[i][j] += mas[i - 1][j]; 
				else
					mas[i][j] += MIN(mas[i - 1][j], mas[i][j - 1]);
		}
	
	i = j = n - 1;
	dp[i][j] = '#';
	dp[0][0] = '#';
	while(i || j) {
		if(i - 1 < 0)
			dp[i][j--] = '#';
		else
			if(j - 1 < 0)
				dp[i--][j] = '#'; 
			else
				if(mas[i - 1][j] > mas[i][j - 1])
					dp[i][--j] = '#';
				else
					dp[--i][j] = '#';	
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			if(dp[i][j] != '#')
				printf("-");
			else
				printf("#");
		printf("\n");
	}
	return 0;
}
