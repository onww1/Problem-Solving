#include <cstdio>
int max(int a, int b) { return a > b ? a : b; }
int N, mx, S, A;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A);
		S += A;
		mx = max(mx, A);
	}
	printf("%d\n", S - mx);
	return 0;
}