#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, a, b, c;
	bool inc, dec;

	cin >> N;
	cout << "Gnomes:" <<'\n';
	for (int i=0; i<N; ++i) {
		cin >> a >> b >> c;
		inc = (a < b) && (b < c);
		dec = (a > b) && (b > c);
		if (inc || dec) cout << "Ordered" << '\n';
		else cout << "Unordered" << '\n';
	}
	return 0;
}