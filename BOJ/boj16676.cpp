#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	if (!N) {
		cout << 1 << '\n';
	}
	else {
		int org = N;
		int cnt = 0;
		while (N>0) {
			cnt++;
			N /= 10;
		}

		int cmp = 1;
		for (int i=1; i<cnt; ++i)
			cmp = cmp * 10 + 1;

		if (org >= cmp) cout << cnt << '\n';
		else cout << (cnt - 1) << '\n';
	}
	return 0;
}