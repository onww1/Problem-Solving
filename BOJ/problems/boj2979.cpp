#include <cstdio>
int cost[4], T[101], L, R;
int main() {
	for (int i = 1; i <= 3; ++i) scanf("%d", cost + i);
	for (int i = 0; i < 3; ++i) {
		scanf("%d %d", &L, &R);
		for (int j = L; j < R; ++j) T[j]++;
	}

	int sum = 0;
	for (int i = 1; i <= 100; ++i) sum += T[i] * cost[T[i]];
	return !printf("%d\n", sum);
}
