#include <iostream>
using namespace std;

void solve(int N) {
	
	int num = 2, cnt = 0;
	while (N % num == 0) {
		cnt++;
		N /= num;
	}
	if (cnt > 0) cout << num << ' ' << cnt << '\n';

	for (num=3; N > 1; num += 2) {
		cnt = 0;
		while (N % num == 0) {
			cnt++;
			N /= num;
		}
		if (cnt > 0) cout << num << ' ' << cnt << '\n';
	}
}

int main() {
	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		solve(N);
	}

	return 0;
}