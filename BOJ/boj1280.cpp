#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX_SIZE = 440'000;
const int INF = 220'000;
const int MOD = 1'000'000'007;

class BIT {
public:
	vector<ll> T;
	vector<ll> A;

	BIT() : T(MAX_SIZE), A(MAX_SIZE, 0) {}

	void update(int p, ll v) {
		while (p <= INF) {
			T[p] += v;
			p += p & (-p);
		}
	}

	ll sum(int p) {
		ll ret = 0;
		while (p > 0) {
			ret += T[p];
			p -= p & (-p);
		}
		return ret;
	}
};

vector<ll> place;
int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	BIT count_fw = BIT();
	BIT sum_fw = BIT();
	place = vector<ll>(MAX_SIZE, 0);
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		cin >> place[i];
		place[i]++;

		count_fw.update(place[i], 1);
		sum_fw.update(place[i], place[i] - 1);
		if (i == 1) continue;

		ll upper = count_fw.sum(INF) - count_fw.sum(place[i] - 1);
		ll lower = count_fw.sum(place[i] - 1);

		ll S_upper = sum_fw.sum(INF) - sum_fw.sum(place[i] - 1);
		ll S_lower = sum_fw.sum(place[i] - 1);

		ll pivot = place[i] - 1;
		ll cost = (S_upper - pivot*upper + pivot*lower - S_lower) % MOD;
		ans = (ans * cost) % MOD;
	}
	if (n == 1) ans = 0;

	cout << ans << '\n';

	return 0;
}