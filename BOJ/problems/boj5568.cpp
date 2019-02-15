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

const int MAX = 10;
pii a[MAX];
set <int> s;
int k, n;

int num_pow(int n) {
	int len = 1;
	while (n) {
		len *= 10;
		n /= 10;
	}
	return len;
}

void solve(int T, int cur, int visited) {
	if (T == k) {
		s.insert(cur);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (visited & (1 << i)) continue;
		solve(T + 1, cur * a[i].second + a[i].first, visited | (1 << i));
	}
}

int main(int argc, char *argv[]) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = num_pow(a[i].first);
	}
	solve(0, 0, 0);
	return !printf("%lu\n", s.size());
}