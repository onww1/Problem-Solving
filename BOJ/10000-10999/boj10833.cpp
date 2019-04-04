#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, s, a, sum = 0;
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> s >> a;
		sum += (a - a / s * s);
	}
	cout << sum << '\n';
	return 0;
}