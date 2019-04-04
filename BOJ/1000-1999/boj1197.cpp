#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

int parent[10001];
int find(int N) {
	if (parent[N] < 0) return N;
	return parent[N] = find(parent[N]);
}

void merge(int N, int M) {
	int A = find(N);
	int B = find(M);
	if (A == B) return;
	parent[B] = A;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int V, E;
	cin >> V >> E;
	vector< pair<int, pair<int, int> > > edges(E);
	int u, v, w;
	for (int i=0; i<E; ++i) {
		cin >> u >> v >> w;
		edges[i] = {w, {u, v}};
	}

	memset(parent, -1, (V+1) * sizeof(int));
	sort(edges.begin(), edges.end());

	long long sum = 0LL;
	int cnt = 0, idx = 0;
	for (auto &it : edges) {
		if (find(it.second.first) == find(it.second.second)) continue;
		sum += (long long)it.first;
		merge(it.second.first, it.second.second);
	}

	cout << sum << '\n';

	return 0;
}