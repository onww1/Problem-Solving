#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int MAX = 1000;
const int MOD = 10007;
int fac[MAX + 1] = { 1 };

int _pow(int base, int exp) {
	int ret = 1;
	while (exp) {
		if (exp % 2) ret = ret * base % MOD;
		base = base * base % MOD;
		exp /= 2;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= MAX; ++i) fac[i] = fac[i - 1] * i % MOD;
	return !printf("%d\n", fac[n] * _pow(fac[k], MOD - 2) % MOD * _pow(fac[n - k], MOD - 2) % MOD);
}