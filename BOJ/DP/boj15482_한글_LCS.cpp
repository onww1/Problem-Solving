#include <cstdio>
#include <locale>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
char S[2][3050];
int L[2], DP[1050][1050];
int main() {
	setlocale(LC_ALL, "korean");

	scanf(" %s %s", S[0], S[1]);
	for (int i = 0; i < 2; ++i) for (L[i] = 0; S[i][L[i]]; ++L[i]);
	L[0] /= 3, L[1] /= 3;
	for (int i = 1; i <= L[0]; ++i) {
		for (int j = 1; j <= L[1]; ++j) {
			if (S[0][3 * (i - 1)] == S[1][3 * (j - 1)] && S[0][3 * (i - 1) + 1] == S[1][3 * (j - 1) + 1] && S[0][3 * (i - 1) + 2] == S[1][3 * (j - 1) + 2])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}
	printf("%d\n", DP[L[0]][L[1]]);
	return 0;
}