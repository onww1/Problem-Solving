#include <iostream>
using namespace std;

int N, M, cnt;
bool edge[51][51];

void reset() {
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			edge[i][j] = false;
		}
	}
	cnt = 0;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;
		reset();

		int u, v;
		for (int i=0; i<M; i++) {
			cin >> u >> v;
			edge[u][v] = edge[v][u] = true;
		}

		for (int i=1; i<=N-2; i++) {
			for (int j=i+1; j<=N-1; j++) {
				if (!edge[i][j]) continue;
				for (int k=j+1; k<=N; k++) {
					if (edge[j][k] && edge[k][i]) 
						cnt++;
				}
			}
		}

		cout << '#' << test_case << ' ' << cnt << '\n';
	}

	return 0;
}