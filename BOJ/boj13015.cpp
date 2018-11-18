#include <iostream>
using namespace std;

void printChar(char c, int len) {
	for (int i=0; i<len; i++)
		cout << c;
}

int main() {
	int N;
	cin >> N;

	printChar('*', N);
	printChar(' ', 2 * N - 3);
	printChar('*', N);
	printChar('\n', 1);

	for (int i=1; i<=N-2; i++) {
		printChar(' ', i);
		printChar('*', 1);
		printChar(' ', N-2);
		printChar('*', 1);
		printChar(' ', 2 * (N - i - 1) - 1);
		printChar('*', 1);
		printChar(' ', N-2);
		printChar('*', 1);
		printChar('\n', 1);
	}

	printChar(' ', N-1);
	printChar('*', 1);
	printChar(' ', N-2);
	printChar('*', 1);
	printChar(' ', N-2);
	printChar('*', 1);
	printChar('\n', 1);

	for (int i=N-2; i>=1; i--) {
		printChar(' ', i);
		printChar('*', 1);
		printChar(' ', N-2);
		printChar('*', 1);
		printChar(' ', 2 * (N - i - 1) - 1);
		printChar('*', 1);
		printChar(' ', N-2);
		printChar('*', 1);
		printChar('\n', 1);
	}

	printChar('*', N);
	printChar(' ', 2 * N - 3);
	printChar('*', N);
	printChar('\n', 1);

	return 0;
}