#include <iostream>
using namespace std;

void draw(int N, int line) {
	if (N == 1) {
		cout << '*';
		return;
	}

	int totLines = 4 * N - 3;
	if (line == 0 || line == N * 4 - 4) {
		for (int i=0; i<totLines; i++)
			cout << '*';
	}
	else if (line == 1 || line == N * 4 - 5) {
		cout << '*';
		for (int i=0; i<totLines-2; i++)
			cout << ' ';
		cout << '*';
	}
	else {
		cout << "* ";
		draw(N-1, line-2);
		cout << " *";
	}
}

int main() {
	int N;
	cin >> N;

	int totLines = N * 4 - 3;
	for (int i=0; i<totLines; i++){
		draw(N, i);
		cout << '\n';
	}

	return 0;
}