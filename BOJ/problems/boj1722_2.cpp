#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll fac[21] = { 1 };

int main(int argc, char *argv[]) {
	for (int i = 1; i <= 20; ++i) fac[i] = fac[i - 1] * i;

	ll n, cmd, k;
	scanf("%lld %lld", &n, &cmd);
	if (cmd == 1) {
		scanf("%lld", &k); --k;
		int ans[21], visited[21] = { 0 };
		for (int i = 0; i < n; ++i) {
			int num = 1;
			while (visited[num] || fac[n - i - 1] <= k) {
				if (!visited[num]) k -= fac[n - i - 1];
				num++;
			}
			ans[i] = num;
			visited[num] = 1;
		}
		for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
		puts("");
	}
	else {
		int a, visited[21] = { 0 };
		ll ans = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a);
			int num = 1;
			while (visited[num] || num < a) {
				if (!visited[num]) ans += fac[n - i - 1];
				num++;
			}
			visited[a] = 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}