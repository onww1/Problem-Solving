#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;

const int MAX = 100;
ll a[MAX + 1], dp[MAX][21], n;

int main(int argc, char *argv[]) {
	scanf("%lld", &n);
	for (int i = 0; i < n; ++i) scanf("%lld", a + i);
	dp[0][a[0]] = 1;
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 0; j <= 20; ++j) {
			if (0 <= j + a[i] && j + a[i] <= 20) dp[i][j + a[i]] += dp[i - 1][j];
			if (0 <= j - a[i] && j - a[i] <= 20) dp[i][j - a[i]] += dp[i - 1][j];
		}
	}

	return !printf("%lld\n", dp[n - 2][a[n - 1]]);
}