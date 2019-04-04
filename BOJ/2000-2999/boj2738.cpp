#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, in;
	cin >> N >> M;

	vector< vector<int> > matrix(N);
	for (int i=0; i<N; i++) {
		matrix[i].resize(M);
		for (int j=0; j<M; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> in;
			matrix[i][j] += in;
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}