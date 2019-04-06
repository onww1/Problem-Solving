#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int tc, N;
	cin >> tc;
	for (int i=0; i<tc; i++) {
		cin >> N;
		int cnt = 0;
		int j;
		for (j=1; j*j<N; j++) {
			if (N % j == 0) cnt += 2;
		}
		if (N == j * j) cnt += 1;
		cout << N << ' ' << cnt << '\n';
	}
	return 0;
}