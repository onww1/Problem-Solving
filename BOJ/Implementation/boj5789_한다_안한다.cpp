#include <stdio.h>
int N, L;
char in[1001];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf(" %s", in);
		for (L = 0; in[L]; ++L);
		puts(in[L / 2] == in[L / 2 - 1] ? "Do-it" : "Do-it-Not");
	}
	return 0;
}