#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

const int move_r[] = {-1, 1, 0, 0};
const int move_c[] = {0, 0, -1, 1};
const int MAX = 100;

int N, M, SR, SC;
char MAP[MAX][MAX + 1];
bool visited[MAX][MAX];

int main() {
	queue <pii> Q;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf(" %s", MAP[i]);
		for (int j = 0; MAP[i][j]; ++j) {
			if (MAP[i][j] == 'W') {
				Q.push({i, j});
				visited[i][j] = true;
			}
		}
	}

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; ++k) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];
			while (MAP[dr][dc] == '+') dr += move_r[k], dc += move_c[k];
			if (!visited[dr][dc]) {
				if (MAP[dr][dc] == '.') {
					Q.push({dr, dc});
					visited[dr][dc] = true;	
				} else if (MAP[dr - move_r[k]][dc - move_c[k]] == '+' && !visited[dr - move_r[k]][dc - move_c[k]]) {
					Q.push({dr - move_r[k], dc - move_c[k]});
					visited[dr - move_r[k]][dc - move_c[k]] = true;
				}
			} 
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) 
			if (MAP[i][j] == '.' && !visited[i][j]) MAP[i][j] = 'P';
		printf("%s\n", MAP[i]);
	}

	return 0;
}