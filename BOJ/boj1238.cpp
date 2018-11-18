#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, X;
	int edge[1001][1001] = {0, };

	cin >> N >> M >> X;
	int u, v, w;
	for (int i=0; i<M; i++) {
		cin >> u >> v >> w;
		edge[u][v] = w;
	}

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			if (i != j && !edge[i][j])
				edge[i][j] = INF;
		}
	}

	for (int k=1; k<=N; k++) {
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=N; j++) {
				if (edge[i][j] > edge[i][k] + edge[k][j])
					edge[i][j] = edge[i][k] + edge[k][j];
			}
		}
	}

	int max = 0;
	for (int i=1; i<=N; i++) {
		int sum = edge[i][X] + edge[X][i];
		max = sum > max ? sum : max;
	}

	cout << max << '\n';

	return 0;
}