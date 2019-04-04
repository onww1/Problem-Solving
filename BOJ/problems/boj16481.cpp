#include <cstdio>
using namespace std;

int main() {
	int r1, r2, r3;
	scanf("%d %d %d", &r1, &r2, &r3);

	int a = r1 * r2 * r3;
	int b = r1 * r2 + r2 * r3 + r3 * r1;
	double r = (double)a / b;
	printf("%.6lf\n", r);
	return 0;
}