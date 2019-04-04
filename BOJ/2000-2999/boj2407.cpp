#include <iostream>
#define MOD 1'00000'00000'00000LL
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;

	ll combi[101][101][2] = {0LL, };
	for (int i=0; i<=N; i++) 
		combi[i][0][0] = combi[i][i][0] = 1LL;
	
	for (int i=2; i<=N; i++) {
		for (int j=1; j<i; j++) {
			combi[i][j][0] = combi[i-1][j][0] + combi[i-1][j-1][0];
			combi[i][j][1] = combi[i][j][0] / MOD;
			combi[i][j][0] %= MOD;
			combi[i][j][1] += (combi[i-1][j][1] + combi[i-1][j-1][1]);
		}
	}

	if (combi[N][M][1]) {
		cout << combi[N][M][1];
		ll tmp = combi[N][M][0];
		ll div = MOD / 10LL;

		while (tmp / div == 0LL) {
			cout << 0;
			div /= 10LL;
		}
		cout << tmp << '\n';
	}
	else cout << combi[N][M][0] << '\n';
	return 0;
}