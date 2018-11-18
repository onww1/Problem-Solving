#include <iostream>
using namespace std;

void draw(int N, int line) {
	if (N == 0) {
		cout << '*';
		return;
	}

	int totLines = 1 << N;
	if (line * 2 < totLines) {
		draw(N-1, line);
		for (int i=0; i<line; i++) cout << ' ';
		draw(N-1, line);	
	}
	else {
		draw(N-1, line - totLines/2);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int totLines = 1 << N;
	for (int line=0; line<totLines; line++) {
		draw(N, line);
		cout << '\n';
	}

	return 0;
}