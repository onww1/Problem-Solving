#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		int cnt = N / 7;
		cnt += (N % 7 > 0);
		cout << cnt << '\n';
	}
	return 0;
}