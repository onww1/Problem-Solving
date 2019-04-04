#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, N, in;
	cin >> T;

	for (int tc=1; tc<=T; ++tc) {
		cin >> N;
		cout << "Case " << tc << ":" << '\n';
		for (int i=0; i<N; ++i) {
			cin >> in;
			if (in < 6) cout << (in + 1) << '\n';
		}
	}
	return 0;
}