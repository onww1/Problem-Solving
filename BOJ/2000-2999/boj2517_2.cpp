#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 5e5;
pii a[MAX + 1];
int n, tree[MAX + 1], ans[MAX + 1];

void update(int node, int val) {
	while (node <= n) {
		tree[node] += val;
		node += (node & -node);
	}
}

int sum(int node) {
	int ret = 0;
	while (node > 0) {
		ret += tree[node];
		node -= (node & -node);
	}
	return ret;
}

int main(int argc, char *argv[]) {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + n);

	int s;
	for (i = 0; i < n; ++i) {
		s = sum(a[i].second - 1);
		ans[a[i].second - 1] = a[i].second - s;
		update(a[i].second, 1);
	}

	for (i = 0; i < n; ++i) printf("%d\n", ans[i]);
	return 0;
}

