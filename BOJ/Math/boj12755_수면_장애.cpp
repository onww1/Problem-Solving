#include <cstdio>
using namespace std;

int get_pow(int base, int exp) {
	int ret = 1;
	while (exp) {
		if (exp % 2) ret *= base;
		base *= base;
		exp /= 2;
	}
	return ret;
}

int cnt[10] = { 0 , 9 , };
int main(int argc, char *argv[]) {
	int n, i, j, s, target;
	scanf("%d", &n);
	for (i = 2, j = 90; i < 9; ++i, j *= 10) cnt[i] = i * j;
	for (i = 0, s = 0; s < n;) s += cnt[++i];
	n -= (s - cnt[i]);
	target = get_pow(10, i - 1) + (n / i - (n % i ? 0 : 1));
	if (n % i == 0) return !printf("%d\n", target % 10);
	return !printf("%d\n", (target / get_pow(10, i - n % i)) % 10);
}