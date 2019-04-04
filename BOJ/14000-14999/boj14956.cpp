#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, M, D = 0;
	cin >> N >> M;

	int r = 0, c = 0;
	while (N > 1) {
		int half = N/2;
		int square = half * half;
		int sector = M / square;

		if (sector == 0) {
			D = (D + 1) % 4;
		}
		else if (sector == 1) {
			if (D == 0) {
				r += half;
			} else if (D == 1) {
				c += half;
			} else if (D == 2) {
				r -= half;
			} else {
				c -= half;
			}
		}
		else if (sector == 2) {
			if (D == 0 || D == 1) {
				r += half;
				c += half;
			} else if (D == 2 || D == 3) {
				r -= half;
				c -= half;
			}
		}
		else if (sector == 3) {
			if (D == 0) {
				c += half;
			} else if (D == 1) {
				r += half;
			} else if (D == 2) {
				c -= half;
			} else {
				r -= half;
			}
			D = (D + 3) % 4;
		}
		N /= 2;
		M %= square;
	}

	cout << r << ' ' << c << '\n';
	return 0;
}