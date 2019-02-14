#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int ans[10001], n;

int solve(int mod) {
	if (ans[mod] > 0) return ans[mod];

	int cnt = 1, n = 1;
	while (n % mod != 0) {
		n = (n * 10 + 1) % mod;
		++cnt;
	}
	return ans[mod] = cnt;
}

int main(int argc, char *argv[]) {
	while (~scanf("%d", &n)) printf("%d\n", solve(n));
	return 0;
}