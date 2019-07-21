#include <iostream>
#include <vector>

std::vector<int> a;
int K, N;

void gen(int prev, int pos) {
	if (pos == K) {
		for(int i = 0; i < K; ++i) {
			std::cout << a[i] <<  " ";
		}
		std::cout << std::endl;
		return;
	}

	for(int i = prev + 1; i <= N; ++i) {
		if (K - 1 - pos + i > N) {
			break;
		}
		a[pos] = i;
		gen(i, pos + 1);
	}
}

int main() {
	std::cin >> N >> K;
	a.resize(K);
	gen(0, 0);
	return 0;
}