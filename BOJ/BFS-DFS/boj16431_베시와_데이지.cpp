#include <iostream>
using namespace std;

int abs(int a) { return a < 0 ? -a : a; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
	int Br, Bc;
	int Dr, Dc;
	int Jr, Jc;

	cin >> Br >> Bc;
	cin >> Dr >> Dc;
	cin >> Jr >> Jc;

	int B = max(abs(Jr - Br), abs(Jc - Bc));
	int D = abs(Jr - Dr) + abs(Jc - Dc);

	if (B > D) cout << "daisy" << '\n';
	else if (B < D) cout << "bessie" << '\n';
	else cout << "tie" << '\n';

	return 0;
}