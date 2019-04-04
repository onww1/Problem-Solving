#include <iostream>
#define MOD 1000000000
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	if (N == 0) cout << 0 << '\n';
	else if (N < 0 && ((-N)%2 == 0)) cout << -1 << '\n';
	else cout << 1 <<'\n';

	N = N < 0 ? -N : N;
	int fibo[1000001] = {0, 1, 1};
	for (int i=3; i<=N; i++) {
		fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
	}

	cout << fibo[N] << '\n';
	return 0;
}