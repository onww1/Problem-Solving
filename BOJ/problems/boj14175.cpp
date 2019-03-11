#include <cstdio>
int M, N, K;
char in[11];
int main() {
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < M; ++i) {
		scanf(" %s", in);
		for (int j = 0; j < K; ++j) {
			for (int k = 0; in[k]; ++k) {
				for (int l = 0; l < K; ++l) {
					printf("%c", in[k]);
				}
			}
			puts("");
		}
	}
	return 0;
}