#include <cstdio>

int main(int argc, char *argv[]) {
	int x[3], y[3], sum = 0;
	for (int i = 0; i < 3; ++i) scanf("%d %d", x + i, y + i);
	for (int i = 0; i < 3; ++i) sum += x[i] * (y[(i + 1) % 3] - y[(i + 2) % 3]);
	return !printf("%d\n", sum > 0 ? 1 : sum < 0 ? -1 : 0);
}