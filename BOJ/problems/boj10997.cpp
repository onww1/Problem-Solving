#include <iostream>
using namespace std;

void print(int num, char c) {
	for (int i=0; i<num; i++)
		cout << c;
}

void draw(int N, int line) {
	if (N == 1) {
		cout << '*';
		return;
	}

	int totLines = 4 * N - 1;
	if (line == 0 || line == totLines - 1) {
		print(totLines-2, '*');
	}
	else if (line == 1) {
		cout << '*';
		print(totLines-3, ' ');
	}
	else if (line == totLines - 2) {
		cout << '*';
		print(totLines-4, ' ');
		cout << '*';
	}
	else if (line == 2) {
		cout << "* ";
		draw(N-1, line-2);
		cout << "**";
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

	int totLines = 4 * N - 1;
	if (N == 1) cout << '*' << '\n';
	else {
		draw(N, 0); cout << '\n';
		cout << '*' << '\n';
		for (int i=2; i<totLines; i++) {
			draw(N, i);
			cout << '\n';
		}
	}

	return 0;
}