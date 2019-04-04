#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = 100;
int K, N, cnt, ans;
vector <int> prime;
priority_queue < int, vector<int>, greater<int> > pq;

int main(int argc, char *argv[]) {
	scanf("%d %d", &K, &N);
	prime.resize(K);
	for (int i = 0; i < K; ++i) scanf("%d", &prime[i]), pq.push(prime[i]);
	while (!pq.empty() && cnt < N) {
		while (ans >= pq.top()) pq.pop();
		ans = pq.top();
		pq.pop();
		cnt++;

		for (int p : prime) {
			if (1LL * ans * p < (1LL << 31))
				pq.push(ans * p);
		}
	}

	return !printf("%d\n", ans);
}