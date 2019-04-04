#include <iostream>
using namespace std;

bool has666(int n) {
	int cnt = 0;
	int i = 1;
	while ( n / i ) {
		if ( (n % (10 * i)) / i == 6 ) {
			cnt++;
		}
		else {
			cnt = 0;
		}

		if (cnt == 3) {
			return true;
		}

		i *= 10;
	}
	return false;
}

int main() {
	int N;
	cin >> N;

	int cnt = 0;
	for (int i=666; ; i++) {
		if (has666(i)) cnt++;
		if (cnt == N) {
			cout << i << '\n';
			break;
		}
	}
	
	return 0;
}