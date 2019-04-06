#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1024;
int A[MAX + 1][MAX + 1], N, M;

int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &A[i][j]);
			A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
		}
	}

	int x, y, xx, yy;
	while (M--) {
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		printf("%d\n", A[xx][yy] - A[xx][y - 1] - A[x - 1][yy] + A[x - 1][y - 1]);
	}

	return 0;
}