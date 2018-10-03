#include <cstdio>
#include <queue>
using namespace std;

struct point
{
	int r, c;
};

int T, N;
int map[1000][1000];
char input[1001];

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

int check(int r, int c){
	if(r < 0 || r >= N || c < 0 || c >= N) return false;
	return true;
}

int main(){
	scanf("%d", &T);
	for(int test_case = 1; test_case <= T; test_case++){
		scanf("%d", &N);
		getchar();

		int cnt = 0, cnt_zeros = 0;
		queue<point> tank;
		queue<point> people;
		queue<point> q;
		for(int i=0; i<N; i++){
			scanf("%s", input);
			for(int j=0; j<N; j++){
				if(input[j] == 'W'){
					map[i][j] = -1;
				}
				else if(input[j] == 'G'){
					map[i][j] = 0;
					cnt_zeros++;
				}
				else if(input[j] == 'T'){
					map[i][j] = 1;
					tank.push({i, j});
				}
				else if(input[j] == 'H'){
					map[i][j] = 2;
					people.push({i, j});
				}
			}
		}

		while(!tank.empty()){
			q.push(tank.front());
			tank.pop();
			
		}
		while(!people.empty()){
			q.push(people.front());
			people.pop();
		}

		while(!q.empty()){
			int r = q.front().r;
			int c = q.front().c;
			q.pop();

			for(int k=0; k<4; k++){
				int dr = r + move_r[k];
				int dc = c + move_c[k];

				if(check(dr, dc) && map[dr][dc] == 0){
					map[dr][dc] = map[r][c];
					if(map[r][c] == 2) cnt++;
					cnt_zeros--;
					q.push({dr, dc});
				}
			}
		}

		cnt += cnt_zeros;
		printf("#%d %d\n", test_case, cnt);
	}

	return 0;
}