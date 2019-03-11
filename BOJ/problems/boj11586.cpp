#include <cstdio>
int N, K;
char in[101][101];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf(" %s", in[i]);
	scanf("%d", &K);
	if (K == 1) for (int i = 0; i < N; ++i) printf("%s\n", in[i]);
	else if (K == 2) {
		for (int i = 0; i < N; ++i) {
			for (int j = N - 1; j >= 0; --j) printf("%c", in[i][j]);
			puts("");
		}
	}
	else if (K == 3) {
		for (int i = N - 1; i >= 0; --i) printf("%s\n", in[i]);
	}
	return 0;
}