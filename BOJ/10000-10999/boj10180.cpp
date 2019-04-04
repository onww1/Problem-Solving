#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N, D;
		cin >> N >> D;

		int V, F, C, cnt = 0;
		while (N--) {
			cin >> V >> F >> C;
			if ( V * F >= C * D ) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}