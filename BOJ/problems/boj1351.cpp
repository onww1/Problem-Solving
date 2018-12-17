#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct a {
	ll N;
	ll val;
};

vector<a> cache;

ll find(ll N) {
	for (a item : cache) {
		if (item.N == N) {
			return item.val;
		}
	}
	return -1LL;
}

ll solve(ll N, ll P, ll Q) {
	if (N == 0) return 1;
	ll ret = find(N);
	if (ret != -1) return ret;

	ret = solve(N/P, P, Q) + solve(N/Q, P, Q);
	cache.push_back({N, ret});
	return ret;
}

int main(int argc, char const *argv[])
{
	ll N, P, Q;
	cin >> N >> P >> Q;

	cout << solve(N, P, Q) << '\n';

	return 0;
}