#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll combi[31][31] = {0, };
	for (int i=0; i<=30; i++)
		combi[i][0] = combi[i][i] = 1LL;

	for (int i=2; i<=30; i++) {
		for (int j=1; j<=i; j++) {
			combi[i][j] = combi[i-1][j] + combi[i-1][j-1];
		}
	}

	int R, C, W;
	cin >> R >> C >> W;

	ll sum = 0LL;
	for (int i=0; i<W; i++) {
		for (int j=0; j<=i; j++) {
			sum += combi[R-1+i][C-1+j];
		}
	}
	cout << sum << '\n';

	return 0;
}