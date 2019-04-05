#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	bool map[100][100] = {false, };
	int pos[4];
	for (int i=0; i<4; ++i) {
		for (int j=0; j<4; ++j) {
			cin >> pos[j];
		}
		for (int r=pos[0]; r<pos[2]; ++r) {
			for (int c=pos[1]; c<pos[3]; ++c) {
				map[r][c] = true;
			}
		}
	}

	int area = 0;
	for (int i=0; i<100; ++i) {
		for (int j=0; j<100; ++j) {
			if (map[i][j]) area++;
		}
	}

	cout << area << '\n';

	return 0;
}