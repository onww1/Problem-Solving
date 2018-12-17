#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, M, sum = 0, max;
	ll T[100000];

	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> T[i];
		if (i < M) sum += T[i];
	}

	max = sum;
	for (int i=M; i<N; i++) {
		sum -= T[i-M];
		sum += T[i];
		max = sum > max ? sum : max;
	}
	cout << max << '\n';
	return 0;
}