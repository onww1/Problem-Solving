#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector< vector<int> > edge(N);
	for (int i=0; i<N; i++) {
		edge[i].resize(N);
		for (int j=0; j<N; j++)
			if (i != j) edge[i][j] = INF;
	}

	int u, v, w;
	for (int i=0; i<M; i++) {
		cin >> u >> v >> w;
		if (edge[u-1][v-1] > w)
			edge[u-1][v-1] = w;
	}

	for (int k=0; k<N; k++) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (edge[i][j] > edge[i][k] + edge[k][j])
					edge[i][j] = edge[i][k] + edge[k][j];
			}
		}
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)
			cout << (edge[i][j] == INF?0:edge[i][j]) << ' ';
		cout << '\n';
	}
	return 0;
}