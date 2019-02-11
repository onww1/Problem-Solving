#include <cstdio>
typedef long long ll;

const int MAX = 90;
ll fibo[MAX + 1] = { 0, 1 };

int main(int argc, char *argv[]) {
	int n, i;
	scanf("%d", &n);
	for (i = 2; i <= n; ++i) fibo[i] = fibo[i - 1] + fibo[i - 2];
	return !printf("%lld\n", fibo[n]);
}