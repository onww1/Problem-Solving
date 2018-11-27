#include <iostream>
using namespace std;

int T, N, W, map[10000][2], dp[10000][2][4];

void initialize() {
	cin >> N >> W;
	for (int j=0; j<2; j++) {
		for (int i=0; i<N; i++) {
			cin >> map[i][j];
			for (int k=0; k<4; k++)
				dp[i][j][k] = 0;
		}
	}
}

void check() {
	for (int j=0; j<2; j++) {
		for (int i=0; i<N; i++) {
			int dst = W - map[i][j];
			dp[i][j][0] = 1;
			dp[i][j][1] = (map[i][(j+1)%2] <= dst ? 1 : 0);
			dp[i][j][2] = (map[(i+1)%N][j] <= dst ? 1 : 0);
			dp[i][j][3] = (map[(i-1+N)%N][j] <= dst ? 1 : 0);
		}
	}
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		initialize();
		check();

		for (int j=0; j<2; j++) {
			for (int i=1; i<N; i++) {
				
			}
		}
	}
	
	return 0;
}