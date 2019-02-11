#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main(int argc, char *argv[]) {
	int N, L, a, i;
	scanf("%d %d", &N, &L);

	priority_queue < pii, vector<pii>, greater<pii> > pq;
	int mn, idx = 1;
	scanf("%d", &mn); printf("%d ", mn);
	for (i = 2; i <= N; ++i) {
		scanf("%d", &a);
		pq.push({ a, i });

		while (!pq.empty() && (!(i - L + 1 <= idx && idx <= i) || mn > pq.top().first)) {
			mn = pq.top().first;
			idx = pq.top().second;
			pq.pop();
		}
		printf("%d ", mn);
	}
	return !printf("\n");
}

