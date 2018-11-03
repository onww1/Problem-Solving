#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int max = 0, r, c, input;
	for (int i=1; i<=9; i++) {
		for (int j=1; j<=9; j++) {
			cin >> input;
			if (input > max) {
				max = input;
				r = i;
				c = j;
			}
		}
	}

	cout << max << '\n';
	cout << r << ' ' << c << '\n';
	return 0;
}