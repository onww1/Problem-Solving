#include <iostream>
#include <queue>
using namespace std;

int T, N, K, D[1001], DP[1001], W, indegree[1001];
bool edge[1001][1001];

void initialize() {
	cin >> N >> K;
	for (int i=1; i<=N; i++) {
		cin >> D[i];
		DP[i] = D[i];
		indegree[i] = 0;
		for (int j=1; j<=N; j++) {
			edge[i][j] = false;
		}
	}

	int u, v;
	for (int i=0; i<K; i++) {
		cin >> u >> v;
		edge[u][v] = true;
		indegree[v]++;
	}

	cin >> W;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		initialize();

		queue<int> q;
		for (int i=1; i<=N; i++) {
			if (!indegree[i]) {
				q.push(i);
				indegree[i] = -1;
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i=1; i<=N; i++) {
				if (edge[cur][i]) {
					indegree[i]--;
					DP[i] = (DP[i] < D[i] + DP[cur] ? D[i] + DP[cur] : DP[i]);
				}
			}

			for (int i=1; i<=N; i++) {
				if (!indegree[i]) {
					q.push(i);
					indegree[i] = -1;
				}
			}
		}

		cout << DP[W] << '\n';
	}

	return 0;
}