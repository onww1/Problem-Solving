#include <iostream>
using namespace std;

int getUnique(int a, int b, int c) {
	if (a == b) return c;
	if (b == c) return a;
	if (c == a) return b;
	return -1;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int point[3][2];
	for (int i=0; i<3; i++) {
		for (int j=0; j<2; j++) {
			cin >> point[i][j];
		}
	}
	cout << getUnique(point[0][0], point[1][0], point[2][0]) << ' '
		 << getUnique(point[0][1], point[1][1], point[2][1]) << '\n';

	return 0;
}