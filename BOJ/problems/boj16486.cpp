#include <cstdio>
using namespace std;

int main() {
	int d1, d2;
	scanf("%d %d", &d1, &d2);
	double res = 3.141592 * d2 + d1 * 2;
	printf("%.6lf\n", res);
	return 0;
}