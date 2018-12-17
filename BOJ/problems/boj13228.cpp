#include <iostream>
using namespace std;

int get_abs(int a) { return a > 0 ? a : -a; }

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, in[6];
	cin >> T;
	while (T--) {
		for (int i=0; i<6; ++i) cin >> in[i];
		cout << (abs(in[0] - in[3]) + abs(in[1] - in[4]) + in[2] + in[5]) << '\n';
	}

	return 0;
}