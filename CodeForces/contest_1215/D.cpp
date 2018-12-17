#include <iostream>
#include <vector>
#include <queue>
#define MOD 998244353
using namespace std;

long long solve(int N) {
	if (N == 0) return 0LL;
	if (N == 1) return 2LL;

	long long res = 1LL;
	if (N%2) res *= 2LL;
	return (res * solve(N/2) * solve(N/2)) % MOD;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, N, M;
	vector<int> vertex;
	vector<int> visited;
	vector< vector<int> > edges;
	bool isValid;

	cin >> T;
	while (T--) {
		cin >> N >> M;
		visited.resize(N+1, 0);
		edges.resize(N+1, vector<int>());
		isValid = true;

		int u, v;
		for (int i=0; i<M; ++i) {
			cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}

		queue<int> q;
		int cnt = 0;
		long long res = 1LL;
		for (int i=1; isValid && i<=N; ++i) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = 1;
				cnt = 1;

				while (isValid && !q.empty()) {
					int vertice = q.front();
					q.pop();

					int len = edges[vertice].size();
					for (int i=0; i<len; ++i) {
						if (visited[edges[vertice][i]]) {
							if ((visited[edges[vertice][i]] % 2) == (visited[vertice] % 2)) {
								isValid = false;
								break;
							}
						}
						else {
							visited[edges[vertice][i]] = visited[vertice] + 1;
							q.push(edges[vertice][i]);
							cnt++;
						}
					}
				}
				long long pres = (solve(cnt/2) + solve(cnt%2?cnt/2+1:cnt/2))%MOD;
				res = (res * pres) % MOD;
			}
		}
		cout << (isValid?res:0) << '\n';
	}

	return 0;
}