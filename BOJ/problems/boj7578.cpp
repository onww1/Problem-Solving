#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 5e5;
const int MOD = 1e9 + 7;
const int INF = 0x7f7f7f7f;
ll N, A[MAX + 1][2], idx[MAX + 1], tree[MAX + 1], pos[MAX + 1];

void update(int node, ll diff) {
	while (node <= N) {
		tree[node] += diff;
		node += node & -node;
	}
}

ll sum(int node) {
	ll ret = 0;
	while (node > 0) {
		ret += tree[node];
		node -= node & -node;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	scanf("%lld", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld", &A[i][0]);
		idx[i] = A[i][0];
	}
	sort(idx, idx + N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld", &A[i][1]);
		A[i][0] = lower_bound(idx, idx + N, A[i][0]) - idx;
		A[i][1] = lower_bound(idx, idx + N, A[i][1]) - idx;
		pos[A[i][1]] = i;
	}
	
	ll cnt = 0;
	update(pos[A[0][0]] + 1, 1);
	for (int i = 1; i < N; ++i) {
		int p = pos[A[i][0]];
		cnt += sum(N) - sum(p + 1);
		update(p + 1, 1);
	}

	return !printf("%lld\n", cnt);
}