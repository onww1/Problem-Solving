#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, A[100000] = {0, }, D[100000] = {0, };
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> A[i];
		D[A[i]]++;
	}

	bool isValid = (D[0] == N || D[0] == 0);
	for (int i=1; i<N; ++i) {
		if (D[i] % (N-i) != 0) {
			isValid = false;
		}
	}

	if (!isValid) {
		cout << "Impossible" << '\n';
	} else {
		cout << "Possible" << '\n';
		if (D[0]) {
			cout << 1;
			for (int i=1; i<N; ++i)
				cout << ' ' << 1;
			cout << '\n';
		} else {
			int cnt = 0;
			int C[100000] = {0, };
			for (int i=0; i<N; ++i) {
				if (D[A[i]] % (N-A[i]) == 0) {
					C[A[i]] = ++cnt;
				}
				cout << C[A[i]] << ' ';
				--D[A[i]];
			}
			cout << '\n';
		}
	}

	return 0;
}