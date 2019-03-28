#include <cstdio>

int N, A[1000], V[1000];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	for (int i = 0, cur = 0, T; i < N; ++i) {
		printf("%d ", cur + 1);
		V[cur] = 1; T = A[cur];
		if (i == N - 1) break;

		if (T > 0) {
			T = T % (N - i - 1) ? T % (N - i - 1) : N - i - 1;
			while (V[cur] || T) {
				cur = (cur + 1) % N;
				if (!V[cur]) T--;
			}
		} else {
			T *= -1;
			T = T % (N - i - 1) ? T % (N - i - 1) : N - i - 1;
			while (V[cur] || T) {
				cur = (cur + N - 1) % N;
				if (!V[cur]) T--;
			}
		}
	}
	puts("");
	return 0;
}