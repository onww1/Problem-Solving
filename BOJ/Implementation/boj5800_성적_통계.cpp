#include <stdio.h>
int K, N, A, S[101];

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
void init() { for (int i = 0; i <= 100; ++i) S[i] = 0; }

int main() {
	scanf("%d", &K);
	for (int cls = 1; cls <= K; ++cls) {
		init();
		scanf("%d", &N);
		int mx = 0, mn = 100, mx_gap = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &A);
			mx = max(mx, A);
			mn = min(mn, A);
			S[A]++;
		}
		for (int i = 0, prev = -1; i <= 100; ++i) {
			if (S[i]) {
				if (prev == -1) prev = i;
				else {
					mx_gap = max(mx_gap, i - prev);
					prev = i;
				}
			}
		}
		printf("Class %d\n", cls);
		printf("Max %d, Min %d, Largest gap %d\n", mx, mn, mx_gap);
	}
	return 0;
}