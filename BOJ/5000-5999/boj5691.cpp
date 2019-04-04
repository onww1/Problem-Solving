#include <cstdio>
int main() {
	for (long long A, B; 1;) {
		scanf("%lld %lld", &A, &B);
		if (!A && !B) break;
		if (2 * A - B <= A) printf("%lld\n", 2 * A - B);
		else if (2 * B - A >= B) printf("%lld\n", 2 * B - A);
	}
	return 0;
}