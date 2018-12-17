#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, S, A[1001], B[1001];
	cin >> N >> S;
	for (int i=1; i<=N; i++) {
		cin >> A[i];
	}
	for (int i=1; i<=N; i++) {
		cin >> B[i];
	}

	if (A[1] == 0) cout << "NO" << '\n';
	else {
		if (A[S] == 1) cout << "YES" << '\n';
		else {
			if (B[S] == 0) cout << "NO" << '\n';
			else {
				int i=S+1;
				for (; i<=N; i++) {
					if(A[i] && B[i]) {
						cout << "YES" << '\n';
						break;
					}
				}
				if (i == N+1) cout << "NO" << '\n';
			}
		}
	}

	return 0;
}