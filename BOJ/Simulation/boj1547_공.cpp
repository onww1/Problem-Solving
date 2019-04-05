#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, a, b, cur = 1;
	cin >> N;
	while (N--) {
		cin >> a >> b;
		if (a == cur) cur = b;
		else if (b == cur) cur = a;
	}
	cout << cur << '\n';
	return 0;
}