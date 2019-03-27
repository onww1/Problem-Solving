#include <cstdio>
#include <cstring>

int N, cnt[2][26];
char A[1001];

int main() {
	scanf("%d", &N);
	for (int i = 0, j; i < N; ++i) {
		memset(cnt, 0, sizeof(cnt));
		for (j = 0; j < 2; ++j) {
			scanf(" %s", A);
			for (int k = 0; A[k]; ++k) cnt[j][A[k] - 'a']++;
		}
		for (j = 0; j < 26; ++j) if (cnt[0][j] != cnt[1][j]) break;
		puts(j == 26 ? "Possible" : "Impossible");
	}
	return 0;
}