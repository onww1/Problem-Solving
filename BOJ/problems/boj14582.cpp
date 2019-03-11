#include <cstdio>
int A[9], B[9], f, SA, SB;
int main() {
	for (int i = 0; i < 9; ++i) scanf("%d", A + i);
	for (int i = 0; i < 9; ++i) scanf("%d", B + i);
	for (int i = 0; i < 9; ++i) {
		SA += A[i];
		if (SA > SB) f = 1;
		SB += B[i];
	}
	printf("%s\n", f ? "Yes" : "No");
	return 0;
}