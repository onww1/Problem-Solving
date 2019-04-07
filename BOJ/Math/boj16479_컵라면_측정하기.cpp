#include <cstdio>
using namespace std;

int main() {
	int K, D1, D2;
	scanf("%d %d %d", &K, &D1, &D2);

	double c_square = K * K;
	int diff = D1 - D2;
	diff *= diff;
	double a_square = (double)diff / 4;
	double result = c_square - a_square;
	printf("%.6lf\n", result);

	return 0;
}