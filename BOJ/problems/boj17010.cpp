#include <cstdio>
int T, N; char C;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %c", &N, &C);
		for (int i = 0; i < N; ++i) printf("%c", C);
		puts("");
	}
	return 0;
}