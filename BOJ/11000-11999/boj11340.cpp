#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	while (N--) {
		int a, b, c;
		cin >> a >> b >> c;
		int res = 9000 - 15 * a - 20 * b - 25 * c;
		res = res / 40 + (res%40?1:0);
		if (res > 100) cout << "impossible" << '\n';
		else cout << res << '\n';
	}
	return 0;
}