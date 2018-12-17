#include <cstdio>
#include <queue>
using namespace std;

struct Point {
	int r, c, flag;
};

int N, M;
char map[1000][1001] = {0, };
int visited[1000][1000][2] = {0, };

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool check(int r, int c) {
	if(r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%s", map[i]);
	}

	queue<Point> q;

	visited[0][0][0] = 1;
	q.push({0, 0, 0});

	while(!q.empty()) {
		Point p = q.front();
		q.pop();

		int r = p.r;
		int c = p.c;
		int flag = p.flag;
		
		for(int k=0; k<4; k++) {
			int dr = r + move_r[k];
			int dc = c + move_c[k];

			if(check(dr, dc)) {
				if( map[dr][dc] == 'R' && !visited[dr][dc][flag] ) {
					visited[dr][dc][flag] = visited[r][c][flag] + 1;
					q.push({dr, dc, flag});
				}
				else if( map[dr][dc] == 'H' && !flag) {
					visited[dr][dc][1] = visited[r][c][0] + 1;
					q.push({dr, dc, 1});
				}
			}
		}
	}

	int result;
	if(visited[N-1][M-1][0] == 0 && visited[N-1][M-1][1] == 0)
		result = -1;
	else if(visited[N-1][M-1][0] == 0 && visited[N-1][M-1][1])
		result = visited[N-1][M-1][1];
	else if(visited[N-1][M-1][1] == 0 && visited[N-1][M-1][0])
		result = visited[N-1][M-1][0];
	else
		result = (visited[N-1][M-1][0] > visited[N-1][M-1][1])?visited[N-1][M-1][1]:visited[N-1][M-1][0];

	printf("%d\n", result==-1?result:result-1);
	return 0;
}