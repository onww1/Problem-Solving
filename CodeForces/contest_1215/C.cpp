#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<ll> a(N + 1);
	for (int i=1; i<=N/2; ++i) {
		cin >> a[i];
	}

	a[N] = a[1];
	a[1] = 0;

	for (int i=2; i<=N/2; ++i) {
		a[N + 1 - i] = a[N + 2 - i];
		if (a[i] - a[N + 1 - i] < a[i-1]) {
			a[N + 1 - i] -= (a[i-1] - a[i] + a[N + 1 - i]);
		}
		a[i] -= a[N + 1 - i];
	}

	cout << a[1];
	for (int i=2; i<=N; ++i) {
		cout << ' ' << a[i];
	}
	cout << '\n';
	return 0;
}