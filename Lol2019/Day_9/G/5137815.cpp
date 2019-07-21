#include <cstdio>

const int A = 26;
int n;
char s[101];
bool used[A], used_pair[A][A];
	
int main() {
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; ++i) {
		used[s[i] - 'a'] = true;
		if (i + 1 < n) used_pair[s[i] - 'a'][s[i + 1] - 'a'] = true;
	}
	for (int i = 0; i < A; ++i)
		if (!used[i]) {
			printf("%c\n", 'a' + i);
			return 0;	
		}
	for (int i = 0; i < A; ++i)
		for (int j = 0; j < A; ++j)
			if (!used_pair[i][j]) {
				printf("%c%c\n", 'a' + i, 'a' + j);
				return 0;
			}
	return 0;
}
