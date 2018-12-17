#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, C, M, P[1001][1001] = { 0, };
	int from, to, num, cur = 0;

	cin >> N >> C >> M;
	for (int i=0; i<M; i++) {
		cin >> from >> to >> num;
		P[from][to] = num;
	}

	cout << N << ' ' << C << '\n' << M << '\n';
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cout << P[i][j] << '\t';
		}
		cout << '\n';
	}

	return 0;
}