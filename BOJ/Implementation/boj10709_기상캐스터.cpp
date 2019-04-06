#include <cstdio>
#include <cstring>
char MAP[101];
int H, W, A[100][100];

int main() {
	scanf("%d %d", &H, &W);
	memset(A, -1, sizeof(A));
	for (int i = 0; i < H; ++i) {
		scanf(" %s", MAP);
		for (int j = 0; MAP[j]; ++j) {
			if (MAP[j] == 'c') A[i][j] = 0;
			else if (j > 0 && A[i][j - 1] >= 0) A[i][j] = A[i][j - 1] + 1;
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) printf("%d ", A[i][j]);
		puts("");
	}
	return 0;
}