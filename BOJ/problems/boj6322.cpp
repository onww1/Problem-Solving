#include <cstdio>
#include <cmath>
int main() {
	for (int a, b, c, T = 1; 1; ++T) {
		scanf("%d %d %d", &a, &b, &c);
		if (!a and !b and !c) break;
		if (T > 1) puts("");
		printf("Triangle #%d\n", T);
		if ((a == -1 and b >= c) or (b == -1 and a >= c)) {
			puts("Impossible.");
			continue;
		}
		if (a == -1) printf("a = %.3Lf\n", (long double)sqrt(c * c - b * b));
		if (b == -1) printf("b = %.3Lf\n", (long double)sqrt(c * c - a * a));
		if (c == -1) printf("c = %.3Lf\n", (long double)sqrt(a * a + b * b));
	}
	return 0;
}