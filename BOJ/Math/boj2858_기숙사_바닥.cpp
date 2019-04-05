#include <cstdio>
int main() {
	int R, B, i;
	scanf("%d %d", &R, &B);
	for (i = 1; i * i <= B; ++i) {
		if (B % i == 0 && (i + B / i + 4) * 2 - 4 == R) {
			printf("%d %d\n", B / i + 2, i + 2);
			break;
		}
	}
	return 0;
}