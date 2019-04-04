#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<ll> stack;
	ll sum = 0LL;
	int K, N;
	cin >> K;
	while (K--) {
		cin >> N;
		if (!N) {
			sum -= stack.back();
			stack.pop_back();
		}
		else {
			sum += (ll)N;
			stack.push_back((ll)N);
		}
	}

	cout << sum << '\n';

	return 0;
}