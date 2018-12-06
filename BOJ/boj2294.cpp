#include <iostream>
#include <cstring>
#define INF 0b0111'1111'0111'1111'0111'1111'0111'1111
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K, x, DP[10001];
	cin >> N >> K;

	memset(DP, 127, sizeof(int) * (K+1));
	DP[0] = 0;
	for (int i=0; i<N; i++) {
		cin >> x;
		for (int j=0; j<=K-x; j++) {
			if (DP[j + x] > DP[j] + 1)
				DP[j + x] = DP[j] + 1;
		}
	}

	cout << (DP[K] == INF ? -1 : DP[K]) << '\n';

	return 0;
}