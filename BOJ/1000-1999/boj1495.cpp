#include <iostream>
using namespace std;

int N, S, M, V;
bool DP[100][1001] = {false, };

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> S >> M >> V;
	if (S - V >= 0) DP[0][S-V] = true;
	if (S + V <= M) DP[0][S+V] = true;
	for (int i=1; i<N; i++) {
		cin >> V;
		for (int j=0; j<=M; j++) {
			if (j - V >= 0 && DP[i-1][j])
				DP[i][j-V] = true;
			if (j + V <= M && DP[i-1][j])
				DP[i][j+V] = true;
		}
	}

	int MAX = -1;
	for (int i=0; i<=M; i++) {
		if (DP[N-1][i])
			MAX = i > MAX ? i : MAX;
	}

	cout << MAX << '\n';
	return 0;
}