#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000;
char A[MAX + 1], B[MAX + 1], ans[MAX + 1];
int L1, L2, DP[MAX + 1][MAX + 1];

int main(int argc, char *argv[]) {
	scanf(" %s %s", A, B);
	L1 = strlen(A), L2 = strlen(B);

	for (int i = 1; i <= L1; ++i) {
		for (int j = 1; j <= L2; ++j) {
			if (A[i - 1] == B[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
			else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	printf("%d\n", DP[L1][L2]);
	int len = DP[L1][L2]; ans[len--] = 0;
	while (len >= 0 && L1 > 0 && L2 > 0) {
		if (A[L1 - 1] == B[L2 - 1]) ans[len--] = A[L1 - 1], L1--, L2--;
		else if (DP[L1][L2 - 1] > DP[L1 - 1][L2]) L2--;
		else L1--;
	}

	return !printf("%s\n", ans);
}