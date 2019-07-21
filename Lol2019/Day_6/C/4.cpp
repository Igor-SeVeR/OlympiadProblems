#include <iostream>

using namespace std;

int main() {
	unsigned long long N;
	cin >> N;
	unsigned long long sqr_N = 0; //число, которое ближе всего к sqrt(N)
	unsigned long long divisor = 0; //делитель числа N, который ближе всего к sqr_N
	while (sqr_N * sqr_N < N) {
		++sqr_N;
		if (N % sqr_N == 0) {
			divisor = sqr_N;
		}
	}
	unsigned long long length, weight;
	length = divisor; // так как торт N*N, то размеры кусочка - devider и N/devider
	weight = N / divisor;
	unsigned long long diam_2 = length*length + weight*weight; // квадрат диагонали прямоугольника
	unsigned long long diam; // диаметр тарелки
	(length < weight) ? diam = weight : diam = length; // диаметр тарелки точно больше максимальной из сторон куска
	while (diam * diam < diam_2) {
		++diam;
	}
	cout << (diam + 1) / 2;
	return 0;
}
