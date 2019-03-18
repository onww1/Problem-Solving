#include <cstdio>
long long N, S, i;
int main() {
	scanf("%lld", &N);
	S = 1 + N;
	for (i = 2; i * i < N; ++i) 
		if (N % i == 0) {
			S += i;
			S += N / i;
		}
	if (i * i == N) S += i;
	return !printf("%lld\n", S);
}