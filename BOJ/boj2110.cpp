#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int count(vector<int>& X, int W) {
	int len = X.size();
	int prev = X[0];
	int cnt = 1;

	for (int i=1; i<len; ++i) {
		if (X[i] - prev >= W) {
			cnt++;
			prev = X[i];
		}
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, C, ma = 0, mi = 1000000001;
	cin >> N >> C;

	vector<int> X(N);
	for (int i=0; i<N; ++i) {
		cin >> X[i];
		ma = X[i] > ma ? X[i] : ma;
		mi = X[i] < mi ? X[i] : mi;
	}

	sort(X.begin(), X.end());
	
	int left = 0, right = ma - mi + 1, mid, cnt;
	while (left + 1 < right) {
		mid = (left + right)/2;
		cnt = count(X, mid);
		if (cnt < C) right = mid;
		else left = mid;
	}
	if (cnt < C) mid--;

	cout << mid << '\n';

	return 0;
}
