#include <stdio.h>
int M, D;
int main() {
	scanf("%d %d", &M, &D);
	D += 100 * M;
	if (D == 218) puts("Special");
	else if (D < 218) puts("Before");
	else puts("After");
	return 0;
}