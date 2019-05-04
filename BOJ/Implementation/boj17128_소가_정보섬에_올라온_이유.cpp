#include <cstdio>
const int MAX = 2e5;
int N, Q, S, A[MAX], P[MAX];
int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	P[3] = A[0] * A[1] * A[2] * A[3];
	S = P[3];
	for (int i = 4; i < N + 3; ++i) {
		P[i % N] = P[(i + N - 1) % N] / A[(i + N - 4) % N] * A[i % N];
		S += P[i % N];
	}
	
	for (int i = 0, C; i < Q; ++i) {
		scanf("%d", &C); C--;
		int sum = 0;
		for (int j = C; j < C + 4; ++j) {
			P[j % N] *= -1;
			sum += P[j % N];
		}
		S += 2 * sum;
		printf("%d\n", S);
	}
	return 0;
}