#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	ll sum = 0LL;
	ll in;
	for (int i=0; i<N * N; i++) {
		cin >> in;
		sum += in;
	}

	cout << sum << '\n';
	return 0;
}