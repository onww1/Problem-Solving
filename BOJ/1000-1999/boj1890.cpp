#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	vector< vector<int> > map;

	cin >> N;
	map.resize(N);
	for (int i=0; i<N; i++) {
		map[i].resize(N);
		for (int j=0; j<N; j++)
			cin >> map[i][j];
	}

	vector< vector<ll> > cnt(N);
	for (int i=0; i<N; i++) cnt[i].resize(N);

	cnt[0][0] = 1LL;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (i == N-1 && j == N-1) break;
			if (j + map[i][j] < N) cnt[i][j + map[i][j]] += cnt[i][j];
			if (i + map[i][j] < N) cnt[i + map[i][j]][j] += cnt[i][j];
		}
	}

	cout << cnt[N-1][N-1] << '\n';

	return 0;
}