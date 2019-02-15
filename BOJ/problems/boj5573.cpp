#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int a[MAX + 1][MAX + 1], h, w, n;
int DP[MAX + 1][MAX + 1];

int main(int argc, char *argv[]) {
	scanf("%d %d %d\n", &h, &w, &n);
	DP[0][0] = n;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%d", &a[i][j]);
			if (j < w - 1) DP[i][j + 1] += (DP[i][j] + a[i][j]) / 2;
			if (i < h - 1) DP[i + 1][j] += (DP[i][j] + 1 - a[i][j]) / 2;
		}
	}
	
	int r = 0, c = 0;
	while (r < h && c < w) {
		if (DP[r][c] % 2 == 0) a[r][c] = 1 - a[r][c];
		
		if (a[r][c]) ++c;
		else ++r;
	}

	return !printf("%d %d\n", r + 1, c + 1);
}