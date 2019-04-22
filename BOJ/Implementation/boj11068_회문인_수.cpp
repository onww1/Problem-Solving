#include <stdio.h>
bool isPalindrome(int base, int L, int n, int *A) {
	if (!n) {
		bool ret = true;
		for (int i = 0; i < L / 2; ++i) {
			if (A[i] != A[L - 1 - i]) {
				ret = false;
				break;
			}
		}
		return ret;
	}

	A[L] = n % base;
	return isPalindrome(base, L + 1, n / base, A);
}

int N, S, AA[25];
int main() {
	scanf("%d", &N);
	for (int i = 0, j; i < N; ++i) {
		scanf("%d", &S);
		for (j = 2; j <= 64; ++j) 
			if (isPalindrome(j, 0, S, AA)) break;
		puts(j > 64 ? "0" : "1");
	}
	return 0;
}