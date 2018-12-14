#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll count(vector<int>& X, ll L) {
	int len = X.size();
	ll cnt = 0;
	for (int i=0; i<len; ++i) {
		cnt += (X[i] / L);
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll K, N, ma = 0;
	cin >> K >> N;

	vector<int> X(K);
	for (int i=0; i<K; ++i) {
		cin >> X[i];
		ma = X[i] > ma ? X[i] : ma;
	}

	ll left = 0, right = ma + 1, mid;
	ll cnt;
	while (left + 1 < right) {
		mid = (left + right)/2;
		cnt = count(X, mid);
		if (cnt < N) right = mid;
		else left = mid;
	}
	if (cnt < N) mid--;
	cout << mid << '\n';
	return 0;
}