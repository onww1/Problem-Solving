#include <cstdio>
long long ans = 0;
char A[10001], B[10001];
int main() {
	scanf(" %s %s", A, B);
	for (int i = 0; A[i]; ++i) {
		for (int j = 0; B[j]; ++j) {
			ans += (A[i] - '0') * (B[j] - '0');
		}
	}
	return !printf("%lld\n", ans);
}