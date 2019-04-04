#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, N;
	cin >> T;
	for (int i=0; i<T; ++i) {
		cin >> N;
		cout << (N *(N+1) /2) << ' ' << (N*N) << ' ' << (N*(N+1)) << '\n';
	}
	return 0;
}