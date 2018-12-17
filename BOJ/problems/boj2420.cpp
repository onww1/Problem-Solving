#include <iostream>
using namespace std;

typedef long long ll;

ll my_abs(ll val) {
	return ((val > 0) ? val : -val);
}

int main() {
	ll N, M;
	cin >> N >> M;
	cout << my_abs(N-M) << '\n';
	return 0;
}