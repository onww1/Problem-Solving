#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 4000;
char A[MAX + 1], B[MAX + 1];
int L1, L2, mx, DP[MAX + 1][MAX + 1];

int main(int argc, char *argv[]) {
	scanf(" %s %s", A, B);
	L1 = strlen(A), L2 = strlen(B);
	
	for (int i = 1; i <= L1; ++i) {
		for (int j = 1; j <= L2; ++j) {
			if (A[i - 1] == B[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
			mx = max(mx, DP[i][j]);
		}
	}

	return !printf("%d\n", mx);
}