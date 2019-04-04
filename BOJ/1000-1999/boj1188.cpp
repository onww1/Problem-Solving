#include <cstdio>
int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }
int main() {
	int N, M, G;
	scanf("%d %d", &N, &M);
	G = _gcd(N, M);
	N /= G, M /= G;
	return !printf("%d\n", (M - 1) * G);
}
