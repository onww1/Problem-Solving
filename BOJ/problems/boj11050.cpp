#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(int argc, char *argv[]) {
	int n, k, fac[11] = { 1 };
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= 10; ++i) fac[i] = fac[i - 1] * i;
	return !printf("%d\n", fac[n] / fac[k] / fac[n - k]);
}