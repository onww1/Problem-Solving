#include <cstdio>
int T, A, B, C;
char op;
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %c %d", &A, &op, &B);
		if (op == '+') A += B;
		else A -= B;
		scanf(" %c %d", &op, &C);
		if (A == C) printf("Case %d: YES\n", tc);
		else printf("Case %d: NO\n", tc);
	}
	return 0;
}