#include <cstdio>
char A[10], C[1000][10];
int N, cnt, idx[1000];
int main() {
	scanf(" %s %d", A, &N);
	for (int i = 0; i < N; ++i) {
		scanf(" %s", C[i]);
		bool flag = true;
		for (int j = 0; j < 9; ++j) {
			if (A[j] == '*') continue;
			if (A[j] != C[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag) idx[cnt++] = i;
	}

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i) printf("%s\n", C[idx[i]]);
	return 0;
}