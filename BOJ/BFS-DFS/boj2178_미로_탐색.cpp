#include <cstdio>
#include <queue>
#include <utility>

int map[101][101] = {0, };
int visited[101][101] = {0, };
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

int main(void){
	std::queue< std::pair<int,int> > q;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%1d", &map[i][j]);
		}
	}

	q.push( std::make_pair(1, 1) );
	visited[1][1] = 1;

	while(!q.empty()){
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			if(map[row + dx[i]][col + dy[i]] == 1 && !visited[row + dx[i]][col + dy[i]]){
				visited[row + dx[i]][col + dy[i]] = 1;
				map[row + dx[i]][col + dy[i]] = map[row][col] + 1;
				q.push( std::make_pair(row+dx[i], col+dy[i]) );
			}
		}
	}

	printf("%d\n", map[n][m]);
	return 0;
}