#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long T, N;
	cin >> T;

	while(T--) {
		cin >> N;
		if (N == 1) {
			cout << '#' << '\n';
		}
		else {
			for (long long i=0LL; i<N; i++) cout << '#';
			cout << '\n';
			for (long long i=0LL; i<N-2LL; i++) {
				cout << '#';
				for (long long j=0LL; j<N-2LL; j++) cout << 'J';
				cout << '#' << '\n';
			}
			for (long long i=0LL; i<N; i++) cout << '#';
			cout << '\n';
		}

		if (T > 0LL) cout << '\n';
	}

	return 0;
}