#include <stdio.h>
int T, P, M, C, S[501];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &P, &M); C = 0;
		for (int i = 1; i <= M; ++i) S[i] = 0;
		for (int i = 0, in; i < P; ++i) {
			scanf("%d", &in);
			if (S[in]) ++C;
			else S[in] = 1;
		}
		printf("%d\n", C);
	}
	return 0;
}