#include <iostream>
using namespace std;

int pow(int p) {
	int ret = 1;
	for (int i=0; i<p; i++) 
		ret *= 2;
	return ret;
}

void printChar(char c, int len) {
	for (int i=0; i<len; i++)
		cout << c;
}

void draw(int N, int line, int start) {
	if (N == 1) {
		printChar('*', 1);
		return;
	}

	int totLines = pow(N) - 1;
	if (N%2) {
		printChar(' ', totLines - line - 1);
		if (line == 0) {
			printChar('*', 1);
		}
		else if (line == totLines - 1) {
			printChar('*', 2 * totLines - 1);
		}
		else if (line * 2 < totLines - 1) {
			printChar('*', 1);
			printChar(' ', 2 * line - 1);
			printChar('*', 1);
		}
		else {
			printChar('*', 1);
			printChar(' ', line - (totLines - 1) / 2);
			draw(N-1, line - (totLines - 1) / 2, start);
			printChar(' ', line - (totLines - 1) / 2);
			printChar('*', 1);
		}
		if (N != start)
			printChar(' ', totLines - line - 1);
	}
	else {
		printChar(' ', line);
		if (line == 0) {
			printChar('*', 2 * totLines - 1);
		}
		else if (line == totLines - 1){
			printChar('*', 1);
		}
		else if (line * 2 < totLines + 1) {
			printChar('*', 1);
			printChar(' ', (totLines - 1)/2 - line);
			draw(N-1, line-1, start);
			printChar(' ', (totLines - 1)/2 - line);
			printChar('*', 1);
		}
		else {
			printChar('*', 1);
			printChar(' ', totLines - 2 - 2 * (line - (totLines-1)/2));
			printChar('*', 1);
		}
		if (N != start)
			printChar(' ', line);
	}
}

int main() {
	int N;
	cin >> N;

	int totLines = pow(N) - 1;
	for (int line=0; line<totLines; line++) {
		draw(N, line, N);
		cout << '\n';
	}

	return 0;
}