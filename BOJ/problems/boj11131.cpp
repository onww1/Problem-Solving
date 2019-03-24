#include <cstdio>
int main() {
	int T, N, A;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int L = 0, R = 0;
		while (N--) {
			scanf("%d", &A);
			if (A < 0) L -= A;
			else R += A;
		}
		if (L == R) puts("Equilibrium");
		else if (L > R) puts("Left");
		else puts("Right");
	}
	return 0;
}