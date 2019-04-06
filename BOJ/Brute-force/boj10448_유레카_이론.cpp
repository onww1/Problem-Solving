#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &tri, int n, int &sum, bool &isOK, int prev, int t) {
	if (t == 3) {
		if (sum == n) isOK = true;
		return;
	}

	for (int i=prev; !isOK && i<45; ++i) {
		if (tri[i] + sum <= n) {
			sum += tri[i];
			solve(tri, n, sum, isOK, i, t+1);
			sum -= tri[i];
		}
		else break;
	}
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, K;
	cin >> T;

	vector<int> tri(45, 0);
	for (int i=1; i<45; ++i) tri[i] = i * (i+1) / 2;

	int sum, prev;
	bool isOK;
	while (T--) {
		cin >> K;
		sum = 0;
		isOK = false;
		prev = 1;
		solve(tri, K, sum, isOK, prev, 0);
		cout << (isOK?1:0) << '\n';
	}

	return 0;
}