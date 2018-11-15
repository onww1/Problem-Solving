#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

ll solve(vector<ll>& h, int left, int right) {
	if (left == right) 
		return h[left];

	int mid = ( left + right ) / 2;
	ll ret = max(solve(h, left, mid), solve(h, mid+1, right));

	int lo = mid, hi = mid+1;
	int minHeight = min(h[lo], h[hi]);
	ret = max(ret, minHeight * 2LL);

	while (left < lo || hi < right) {
		if ( hi < right && (lo == left || h[lo-1] < h[hi+1]) ) {
			hi++;
			minHeight = min(minHeight, h[hi]);
		}
		else {
			lo--;
			minHeight = min(minHeight, h[lo]);
		}

		ret = max(ret, (ll)minHeight * (hi - lo + 1));
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	vector<ll> h;

	while (true) {
		cin >> n;
		if (!n) break;

		h.resize(n);
		for (int i=0; i<n; i++)
			cin >> h[i];

		cout << solve(h, 0, n-1) << '\n';
	}

	return 0;
}