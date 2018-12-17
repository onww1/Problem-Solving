#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, N, P, in, cnt = 0;
	cin >> W >> N >> P;
	while (P--) {
		cin >> in;
		if (W <= in && in <= N) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}