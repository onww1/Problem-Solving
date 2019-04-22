#include <stdio.h>
int N, S;
int main() {
	scanf("%d", &N);
	for (int i = 1, in; i <= N; ++i) {
		scanf("%d", &in);
		if (in != i) S++;
	}
	printf("%d\n", S);
	return 0;
}