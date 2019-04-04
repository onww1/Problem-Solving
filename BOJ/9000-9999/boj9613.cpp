#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int gcd_val = b;
	while (a % gcd_val) {
		b = a % gcd_val;
		a = gcd_val;
		gcd_val = b;
	}
	return gcd_val;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, N, A[100];
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i=0; i<N; ++i) {
			cin >> A[i];
		}

		long long sum = 0;
		for (int i=0; i<N-1; ++i) {
			for (int j=i+1; j<N; ++j) {
				sum += (long long)gcd(A[i], A[j]);
			}
		}

		cout << sum << '\n';
	}
	return 0;
}