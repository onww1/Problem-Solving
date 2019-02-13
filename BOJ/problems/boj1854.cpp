#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 1000;
const int INF = 0x7f7f7f7f;
int N, M, K, cnt[MAX + 1], dist[MAX + 1];
vector <pii> edges[MAX + 1];

int main(int argc, char *argv[]) {
	int u, v, w;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back({ v, w });
	}

	priority_queue < pii, vector<pii>, greater<pii> > pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		if (cnt[cur.second] == K) continue;
		if (cnt[cur.second] == K - 1) dist[cur.second] = cur.first;
		cnt[cur.second]++;

		for (pii &next : edges[cur.second]) {
			pq.push({ cur.first + next.second, next.first });
		}
	}

	for (int i = 1; i <= N; ++i) printf("%d\n", cnt[i] == K ? dist[i] : -1);
	return 0;
}