#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, A;
	int t, a, h;
	int max = = -1;
	bool conti
	cin >> N >> A;
	for (int i=0; i<N; i++) {
		cin >> t >> a >> h;
		if (t == 1) {
			int tmp = ( h % A == 0 ) ? h / A - 1 : h / A;
			max = ( tmp * a > max ) ? tmp * a : max;
		}
		else if (t == 2) {
			A += a;
		}
	}

	cout << (max + 1) << '\n';

	return 0;
}