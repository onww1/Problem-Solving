#include <cstdio>
using namespace std;

int main() {
	int a, b, c, af, bd;
	scanf("%d %d %d %d %d", &a, &b, &c, &af, &bd);
	int aa = (c - af) * (a - bd);
	int bb = af * bd + aa;
	aa *= b;
	double ce = (double)aa / bb;
	printf("%.6lf\n", ce);
	return 0;
}