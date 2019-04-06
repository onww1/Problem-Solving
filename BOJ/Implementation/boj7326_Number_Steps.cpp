#include <cstdio>
int main() {
	int T, X, Y;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &X, &Y);
		if (X == Y) {
			printf("%d\n", X / 2 * 4 + X % 2);
		} else if (X == Y + 2) {
			printf("%d\n", (X - 2) / 2 * 4 + 2 + X % 2);
		} else puts("No Number");
	}
	return 0;
}