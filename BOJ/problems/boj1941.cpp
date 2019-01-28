#include <cstdio>
using namespace std;

const int move_r[] = {-1, 1, 0, 0}, move_c[] = {0, 0, -1, 1};
char in[5][6];
bool chk[1 << 25];
int cnt = 0;

void solve(int T, int scnt, int status) {
	if (chk[status]) return;
	chk[status] = true;
	if (T == 7) {
		if (scnt >= 4) ++cnt;
		return;
	}

	int r, c;
	for (int i = 0; i < 25; ++i) {
		if (!(status & (1 << i))) continue;
		r = i / 5, c = i % 5;
		for (int k = 0; k < 4; ++k) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];
			if (dr < 0 || dc < 0 || dr >= 5 || dc >= 5 || (status & (1 << (dr * 5 + dc)))) continue;
			solve(T + 1, scnt + (in[dr][dc] == 'S'? 1 : 0), status | (1 << (dr * 5 + dc)));
		}
	}
}

int main(int argc, char *argv[]) {
	for (int i = 0; i < 5; ++i) scanf(" %s", in[i]);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			solve(1, in[i][j] =='S' ? 1 : 0, 1 << (i * 5 + j));
		}
	}
	return !printf("%d\n", cnt);
}