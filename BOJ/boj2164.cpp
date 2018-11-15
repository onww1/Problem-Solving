#include <iostream>
using namespace std;

int main() {
	int N; 
	cin >> N;

	if (N == 1) cout << "1\n";
	else {
		int pow = 2;
		while (N/(pow*2)) pow *= 2;
		if (pow == N) cout << pow << '\n';
		else {
			cout << (N - pow) * 2 << '\n';
		}
	}

	return 0;
}