#include <iostream>
#define INF 987654321
using namespace std;

int map[2187][2187];

int solve(int r, int c, int w, int &A, int &B, int &C) {
	if (w == 1) {
		return map[r][c];
	}

	int tri = w/3;
	int res[3][3];
	int prev = INF;
	bool isSame = true;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			res[i][j] = solve(r + tri * i, c + tri * j, tri, A, B, C);
			if (!i && !j) prev = res[0][0];
			else if (prev != res[i][j]) isSame = false;
		}
	}

	if (isSame) return prev;
	else {
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				if (res[i][j] == -1) A++;
				else if (res[i][j] == 0) B++;
				else if (res[i][j] == 1) C++;
			}
		}
	}
	return INF;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
		}
	}

	int A = 0, B = 0, C = 0;
	int val = solve(0, 0, N, A, B, C);
	if (val == -1) A++;
	else if (val == 0) B++;
	else if (val == 1) C++;

	cout << A << '\n';
	cout << B << '\n';
	cout << C << '\n';

	return 0;
}