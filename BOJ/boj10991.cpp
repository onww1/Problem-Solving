#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i=1; i<=N; i++) {
		for (int j=N-i; j>0; j--) cout << ' ';
		cout << '*';
		for (int j=i-1; j>0; j--) cout << " *";
		cout << '\n';
	}

	return 0;
}