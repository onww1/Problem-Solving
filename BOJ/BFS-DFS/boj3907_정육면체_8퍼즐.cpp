#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pi;

const int INF = 0x7f7f7f7f;
const int move_r[] = {-1, 0, 1, 0};
const int move_c[] = {0, -1, 0, 1};
int R, C, ans, P[9] = {1}, A[9];
char visited[16796161];
/* WRB, WBR, RBW, RWB, BWR, BRW */

int roll(int status, int direction) {
	if (direction) { // 위, 아래
		return (status + 3) % 6;
	} else { // 왼쪽, 오른쪽
		if (status % 2) return (status + 1) % 6;
		else return (status + 5) % 6;
	}
}

int solve2(int stat) {
	if (visited[stat] > -1 && visited[stat] < 100) return visited[stat];

	queue <pi> Q;
	Q.push({stat, 100}); 
	visited[stat] = 100;

	while (!Q.empty()) {
		int status = Q.front().X / 10;
		int pos = Q.front().X % 10;
		int t = Q.front().Y;
		Q.pop();

		int V = visited[status * 10 + pos];
		if (V > -1 && V < 100) return V + t - 100;
		if (t >= 110) continue;

		for (int k = 0; k < 4; ++k) {
			int dr = pos / 3 + move_r[k];
			int dc = pos % 3 + move_c[k];
			if (dr < 0 || dr >= 3 || dc < 0 || dc >= 3) continue;
			int pp = dr * 3 + dc;
			int offset = 0;
			if (pp < pos) offset = 1;

			int target = status / P[8 - pp - offset] % 6;
			int next = status % P[8 - pp - offset] + status / P[9 - pp - offset] * P[8 - pp - offset];
			target = roll(target, k % 2 == 0);
			next = next % P[7 - pos + offset] + target * P[7 - pos + offset] + next / P[7 - pos + offset] * P[7 - pos + offset] * 6;
			next = next * 10 + pp;

			if (visited[next] >= 100 && visited[next] < t + 1) continue;
			if (visited[next] == -1 || visited[next] >= 100) visited[next] = t + 1;
			else return visited[next] + t - 99;
			if (t < 109) Q.push({next, t + 1});
		}
	}
	return INF;
}

void solve(int tm, int S, int pos) {
	if (tm == 9) {
		ans = min(ans, solve2(S * 10 + pos));
		return;
	}

	if (A[tm] == 6) solve(tm + 1, S, pos);
	else {
		solve(tm + 1, S * 6 + A[tm] * 2, pos);
		solve(tm + 1, S * 6 + A[tm] * 2 + 1, pos);
	}
}

int main(int argc, char *argv[]) {
	for (int i = 1; i < 9; ++i) P[i] = P[i - 1] * 6;

	while (1) {
		scanf("%d %d", &C, &R);
		if (!R && !C) break;
		memset(visited, -1, sizeof(visited));

		int src = 3 * (R - 1) + C - 1;
		queue <pi> Q;
		Q.push({src, 0});
		visited[src] = 0; 
		
		while (!Q.empty()) {
			int status = Q.front().X / 10;
			int pos = Q.front().X % 10;
			int t = Q.front().Y;
			Q.pop();

			if (t >= 20) continue;

			for (int k = 0; k < 4; ++k) {
				int dr = pos / 3 + move_r[k];
				int dc = pos % 3 + move_c[k];
				if (dr < 0 || dr >= 3 || dc < 0 || dc >= 3) continue;
				int pp = dr * 3 + dc;
				int offset = 0;
				if (pp < pos) offset = 1;

				int target = status / P[8 - pp - offset] % 6;
				int next = status % P[8 - pp - offset] + status / P[9 - pp - offset] * P[8 - pp - offset];
				target = roll(target, k % 2 == 0);
				next = next % P[7 - pos + offset] + target * P[7 - pos + offset] + next / P[7 - pos + offset] * P[7 - pos + offset] * 6;
				next = next * 10 + pp;
				if (visited[next] > -1) continue;
				visited[next] = t + 1;
				Q.push({next, t + 1});
			}
		}	

		char c; int ps;
		for (int i = 0; i < 9; ++i) {
			scanf(" %c", &c);
			A[i] = (c == 'W' ? 0 : c == 'R' ? 1 : c == 'B' ? 2 : 6);
			if (A[i] == 6) ps = i;
		}

		ans = INF;
		solve(0, 0, ps);
		printf("%d\n", ans > 30 ? -1 : ans);
	}

	return 0;
}