#include <stdio.h>
int N;
char in[2][1005];
int main() {
	scanf("%d %s %s", &N, in[0], in[1]); N %= 2;
	for (int i = 0; in[0][i]; ++i) {
		if (((in[0][i] - '0') ^ N) + '0' != in[1][i]) return !printf("Deletion failed\n");
	}
	return !printf("Deletion succeeded\n");
}