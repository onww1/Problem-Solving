#include <cstdio>
int main() {
	int N, K, A, S = 0;
	scanf("%d %d", &N, &K);
	while (K--) {
		scanf("%d", &A);
		S += (A + 1) / 2;
	}
	puts(S >= N ? "YES" : "NO");
	return 0;
}