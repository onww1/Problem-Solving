#include <iostream>
using namespace std;

void draw(int N, int line) {
	if (N == 1) {
		cout << '*';
		return;
	}

	if (line * 3 < N) {
		for (int i=0; i<3; i++) {
			draw(N/3, line);
		}
	}
	else if (line * 3 < 2 * N) {
		draw(N/3, line - N/3);
		for (int i=0; i<N/3; i++) cout << ' ';
		draw(N/3, line - N/3);
	}
	else {
		for (int i=0; i<3; i++) {
			draw(N/3, line - 2*N/3);
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int line=0; line<N; line++) {
		draw(N, line);
		cout << '\n';
	}

	return 0;
}