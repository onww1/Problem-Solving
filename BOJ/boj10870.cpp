#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, f[3] = {0, 1, 1};
	cin >> n;
	if (n < 3) cout << f[n] << '\n';
	else {
		for (int i=3; i<=n; ++i) {
			f[0] = f[1];
			f[1] = f[2];
			f[2] = f[0] + f[1];
		}
		cout << f[2] << '\n';
	}
	return 0;
}