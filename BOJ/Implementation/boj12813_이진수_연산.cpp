#include <stdio.h>
char B[2][100001], ans[5][100001];
int main() {
	scanf(" %s %s", B[0], B[1]);
	for (int i = 0; i < 100000; ++i) {
		ans[0][i] = (B[0][i] == '1' && B[1][i] == '1') + '0';
		ans[1][i] = (B[0][i] == '1' || B[1][i] == '1') + '0';
		ans[2][i] = (B[0][i] != B[1][i]) + '0';
		ans[3][i] = (B[0][i] == '0') + '0';
		ans[4][i] = (B[1][i] == '0') + '0';
	}
	for (int i = 0; i < 5; ++i) printf("%s\n", ans[i]);
	return 0;
}