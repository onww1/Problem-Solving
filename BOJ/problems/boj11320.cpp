#include <cstdio>
int T, A, B;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &A, &B);
		A /= B;
		printf("%d\n", A * A);
	}
	return 0;
}