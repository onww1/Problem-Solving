#include <cstdio>
int A[3], D, R;
int main() {
	while (1) {
		for (int i = 0; i < 3; ++i) scanf("%d", A + i);
		if (!A[0] && !A[1] && !A[2]) break;
		if (A[1] * 2 == A[0] + A[2]) printf("AP %d\n", 2 * A[2] - A[1]);
		else printf("GP %d\n", A[2] * A[2] / A[1]);
	}
	return 0;
}