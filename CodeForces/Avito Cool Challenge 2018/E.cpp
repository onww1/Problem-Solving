#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

bool isSquare(ll num) {
	ll val = sqrt((long double)num);
	if ((val - 1) * (val - 1) == num ||
		val * val == num ||
		(val + 1) * (val + 1) == num)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<ll> A(N, 0LL);
	for (int i=1; i<N; i+=2) cin >> A[i];

	bool isValid = true;
	ll num = 1LL, sum = 0LL;
	int idx = 1;
	while (isValid && idx < N) {
		while (!isSquare(num * num - A[idx])) {
			if (2 * num + 1 > A[idx]) {
				isValid = false;
				break;
			}
			num++;
		}
		A[idx-1] = num * num - sum - A[idx];
		sum += A[idx-1] + A[idx];
		idx += 2;
	}

	if (isValid) {
		cout << "Yes" << '\n';
		for (int i=0; i<N; ++i) cout << A[i] << ' ';
		cout << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}