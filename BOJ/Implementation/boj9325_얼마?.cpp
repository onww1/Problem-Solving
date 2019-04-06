#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, cost, N, q, p;
	cin >> T;
	while (T--) {
		cin >> cost;
		cin >> N;
		while (N--) {
			cin >> q >> p;
			cost += (q * p);
		}
		cout << cost << '\n';
	}
	return 0;
}