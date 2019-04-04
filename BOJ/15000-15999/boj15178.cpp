#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, a, b, c;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		int sum = a + b + c;
		cout << a << ' ' << b << ' ' << c << ' ';
		if (sum == 180) cout << "Seems OK" << '\n';
		else cout << "Check" << '\n';
	}
	return 0;
}