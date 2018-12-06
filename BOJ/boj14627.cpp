#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int get_cnt(vector<int>& p, int l) {
	if (l == 0) return 987654321;
	int cnt = 0, len = p.size();
	for (int i=0; i<len; i++) 
		cnt += (p[i] / l);
	return cnt;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int S, C;
	cin >> S >> C;

	ll sum = 0LL;

	vector<int> p(S);
	for (int i=0; i<S; i++) {
		cin >> p[i];
		sum += (ll)p[i];
	}

	int left = -1, right = 1'000'000'001, mid, cnt;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		cnt = get_cnt(p, mid);
		if (cnt >= C) left = mid;
		else right = mid;
	}

	if (cnt < C) mid--;
	cout << (sum - (ll)mid * (ll)C) << '\n';
	return 0;
}