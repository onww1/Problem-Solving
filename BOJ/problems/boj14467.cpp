#include <cstdio>
#include <cstring>
int P[101], C, N, A, V;
int main() {
	scanf("%d", &N);
	memset(P, -1, sizeof(P));
	while (N--) {
		scanf("%d %d", &A, &V);
		if (P[A] == -1) P[A] = V;
		else if (P[A] == 1 - V) {
			++C;
			P[A] = V;
		}
	}
	return !printf("%d\n", C);
}
