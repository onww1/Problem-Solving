#include <cstdio>

int n, m, cnt = 0;
int map[50][50] = {0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int boundaryCheck(int row, int col){
	if(row < 0 || row >= n || col < 0 || col >= m) return 0;
	return 1;
}

int main(void){
	int r, c, d;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &map[i][j]);
		}
	}

	while(1){
		if( !map[r][c] ){
			map[r][c] = 2;
			cnt++;
		}

		d = (d+3)%4;
		if(boundaryCheck(r + dx[d], c + dy[d]) && !map[r + dx[d]][c + dy[d]]){
			r += dx[d]; c += dy[d];
			continue;
		}
		d = (d+3)%4;
		if(boundaryCheck(r + dx[d], c + dy[d]) && !map[r + dx[d]][c + dy[d]]){
			r += dx[d]; c += dy[d];
			continue;
		}
		d = (d+3)%4;
		if(boundaryCheck(r + dx[d], c + dy[d]) && !map[r + dx[d]][c + dy[d]]){
			r += dx[d]; c += dy[d];
			continue;
		}
		d = (d+3)%4;
		if(boundaryCheck(r + dx[d], c + dy[d]) && !map[r + dx[d]][c + dy[d]]){
			r += dx[d]; c += dy[d];
			continue;
		}

		if(boundaryCheck(r - dx[d], c - dy[d]) && map[r - dx[d]][c - dy[d]] != 1){
			r -= dx[d]; c -= dy[d];
			continue;
		} else  break;
	}

	printf("%d\n", cnt);
	return 0;
}