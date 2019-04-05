#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }

int ans[1001], t, n;
int main(int argc, char *argv[]) {

	ans[1] = 3;
	for (int i = 2; i <= 1000; ++i) {
		for (int j = 1; j < i; ++j) if (_gcd(i, j) == 1) ans[i] += 2;
		ans[i] += ans[i - 1];
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}