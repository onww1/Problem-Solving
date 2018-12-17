#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, u, v;
	cin >> N >> M;

	vector< vector<int> > edges(N+1);
	vector<int> indegree(N+1, 0);
	queue<int> q;

	for (int i=0; i<M; ++i) {
		cin >> u >> v;
		edges[u].push_back(v);
		indegree[v]++;
	}

	for (int i=1; i<=N; ++i) 
		if (!indegree[i]) q.push(i);
	
	int cnt = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		cout << node << ' ';
		int len = edges[node].size();
		for (int i=0; i<len; ++i) {
			indegree[edges[node][i]]--;
			if (indegree[edges[node][i]] == 0)
				q.push(edges[node][i]);
		}
		cnt++;
		if (cnt == N) break;
	}

	return 0;
}