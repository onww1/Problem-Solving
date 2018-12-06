#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, N;
	string str;

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		int cnt = 0;
		for (int i=0; i<N; i++) {
			cin >> str;
			if (!str.compare("sheep")) cnt++;
		}
		cout << "Case " << tc << ": This list contains " << cnt << " sheep." << '\n';
		if (tc < T) cout << '\n';
	}
	return 0;
}