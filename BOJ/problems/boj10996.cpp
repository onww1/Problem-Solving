#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i=0; i<2*N; i++) {
		for (int j=0; j<N; j++) {
			cout << ( ( i + j ) % 2 ? ' ' : '*' );
		}
		cout << '\n';
	}

	return 0;
}