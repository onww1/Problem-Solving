#include <iostream>
using namespace std;

typedef long long ll;

bool isEven(ll N) {
	ll sum = 0LL;
	while (N > 0) {
		sum += (N%10);
		N /= 10;
	}
	return sum % 2 == 0;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	ll N;
	cin >> T;

	while (T--) {
		cin >> N;
		ll mul = 1LL;
		while (mul <= 1e8 && isEven(N * mul)) mul++;
		if (mul > 1e8) cout << -1 << '\n';
		else cout << (N * mul) << '\n';
	}
		
	return 0;
}