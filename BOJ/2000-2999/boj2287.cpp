#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K, N, A;
	cin >> K >> N;
	while (N--) {
		cin >> A;
		int min = 987654321;
		dfs(K, A, min, 0);
		if (min > 8) cout << "NO" << '\n';
		else cout << min << '\n';
	}
	return 0;
}