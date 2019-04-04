#include <iostream>
#include <string>
#include <vector>
using namespace std;

char cube[9][13];
int T, N;
string cmd;

void initCube() {
	sprintf(cube[0], "000www000000");
	sprintf(cube[1], "000www000000");
	sprintf(cube[2], "000www000000");
	sprintf(cube[3], "gggrrrbbbooo");
	sprintf(cube[4], "gggrrrbbbooo");
	sprintf(cube[5], "gggrrrbbbooo");
	sprintf(cube[6], "000yyy000000");
	sprintf(cube[7], "000yyy000000");
	sprintf(cube[8], "000yyy000000");
}

void rotateCW(int c_r, int c_c) {
	char tmp = cube[c_r - 1][c_c - 1];
	cube[c_r - 1][c_c - 1] = cube[c_r + 1][c_c - 1];
	cube[c_r + 1][c_c - 1] = cube[c_r + 1][c_c + 1];
	cube[c_r + 1][c_c + 1] = cube[c_r - 1][c_c + 1];
	cube[c_r - 1][c_c + 1] = tmp;

	tmp = cube[c_r - 1][c_c];
	cube[c_r - 1][c_c] = cube[c_r][c_c - 1];
	cube[c_r][c_c - 1] = cube[c_r + 1][c_c];
	cube[c_r + 1][c_c] = cube[c_r][c_c + 1];
	cube[c_r][c_c + 1] = tmp;
}

void rotateCCW(int c_r, int c_c) {
	char tmp = cube[c_r - 1][c_c - 1];
	cube[c_r - 1][c_c - 1] = cube[c_r - 1][c_c + 1];
	cube[c_r - 1][c_c + 1] = cube[c_r + 1][c_c + 1];
	cube[c_r + 1][c_c + 1] = cube[c_r + 1][c_c - 1];
	cube[c_r + 1][c_c - 1] = tmp;

	tmp = cube[c_r - 1][c_c];
	cube[c_r - 1][c_c] = cube[c_r][c_c + 1];
	cube[c_r][c_c + 1] = cube[c_r + 1][c_c];
	cube[c_r + 1][c_c] = cube[c_r][c_c - 1];
	cube[c_r][c_c - 1] = tmp;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	char tmp;
	cin >> T;
	for (int tc=0; tc<T; tc++) {
		cin >> N;
		initCube();

		for (int i=0; i<N; i++) {
			cin >> cmd;
			if (cmd[0] == 'U') {
				if (cmd[1] == '+') {
					rotateCW(1, 4);
					for (int i=0; i<3; i++) {
						tmp = cube[3][i];
						cube[3][i] = cube[3][3+i];
						cube[3][3+i] = cube[3][6+i];
						cube[3][6+i] = cube[3][9+i];
						cube[3][9+i] = tmp;
					}
				}
				else if (cmd[1] == '-') {
					rotateCCW(1, 4);
					for (int i=0; i<3; i++) {
						tmp = cube[3][i];
						cube[3][i] = cube[3][9+i];
						cube[3][9+i] = cube[3][6+i];
						cube[3][6+i] = cube[3][3+i];
						cube[3][3+i] = tmp;
					}
				}
			}
			else if (cmd[0] == 'D') {
				if (cmd[1] == '+') {
					rotateCW(7, 4);
					for (int i=0; i<3; i++) {
						tmp = cube[5][i];
						cube[5][i] = cube[5][9+i];
						cube[5][9+i] = cube[5][6+i];
						cube[5][6+i] = cube[5][3+i];
						cube[5][3+i] = tmp;
					}
				}
				else if (cmd[1] == '-') {
					rotateCCW(7, 4);
					for (int i=0; i<3; i++) {
						tmp = cube[5][i];
						cube[5][i] = cube[5][3+i];
						cube[5][3+i] = cube[5][6+i];
						cube[5][6+i] = cube[5][9+i];
						cube[5][9+i] = tmp;
					}
				}
			}
			else if (cmd[0] == 'F') {
				if (cmd[1] == '+') {
					rotateCW(4, 4);
					for (int i=0; i<3; i++) {
						tmp = cube[2][3+i];
						cube[2][3+i] = cube[5-i][2];
						cube[5-i][2] = cube[6][5-i];
						cube[6][5-i] = cube[3+i][6];
						cube[3+i][6] = tmp;
					}
				}
				else if (cmd[1] == '-') {
					rotateCCW(4, 4);
					for (int i=0; i<3; i++) {
						tmp = cube[2][3+i];
						cube[2][3+i] = cube[3+i][6];
						cube[3+i][6] = cube[6][5-i];
						cube[6][5-i] = cube[5-i][2];
						cube[5-i][2] = tmp;
					}
				}
			}
			else if (cmd[0] == 'B') {
				if (cmd[1] == '+') {
					rotateCW(4, 10);
					for (int i=0; i<3; i++) {
						tmp = cube[0][5-i];
						cube[0][5-i] = cube[5-i][8];
						cube[5-i][8] = cube[8][3+i];
						cube[8][3+i] = cube[3+i][0];
						cube[3+i][0] = tmp;
					}
				}
				else if (cmd[1] == '-') {
					rotateCCW(4, 10);
					for (int i=0; i<3; i++) {
						tmp = cube[0][5-i];
						cube[0][5-i] = cube[3+i][0];
						cube[3+i][0] = cube[8][3+i];
						cube[8][3+i] = cube[5-i][8];
						cube[5-i][8] = tmp;
					}
				}
			}
			else if (cmd[0] == 'L') {
				if (cmd[1] == '+') {
					rotateCW(4, 1);
					for (int i=0; i<3; i++) {
						tmp = cube[i][3];
						cube[i][3] = cube[5-i][11];
						cube[5-i][11] = cube[6+i][3];
						cube[6+i][3] = cube[3+i][3];
						cube[3+i][3] = tmp;
					}
				}
				else if (cmd[1] == '-') {
					rotateCCW(4, 1);
					for (int i=0; i<3; i++) {
						tmp = cube[i][3];
						cube[i][3] = cube[3+i][3];
						cube[3+i][3] = cube[6+i][3];
						cube[6+i][3] = cube[5-i][11];
						cube[5-i][11] = tmp;
					}
				}
			}
			else if (cmd[0] == 'R') {
				if (cmd[1] == '+') {
					rotateCW(4, 7);
					for (int i=0; i<3; i++) {
						tmp = cube[2-i][5];
						cube[2-i][5] = cube[5-i][5];
						cube[5-i][5] = cube[8-i][5];
						cube[8-i][5] = cube[3+i][9];
						cube[3+i][9] = tmp;
					}
				}
				else if (cmd[1] == '-') {
					rotateCCW(4, 7);
					for (int i=0; i<3; i++) {
						tmp = cube[2-i][5];
						cube[2-i][5] = cube[3+i][9];
						cube[3+i][9] = cube[8-i][5];
						cube[8-i][5] = cube[5-i][5];
						cube[5-i][5] = tmp;
					}
				}
			}
		}

		for (int i=0; i<3; i++) {
			for (int j=3; j<6; j++) {
				cout << cube[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}