#include <cstdio>
#include <queue>
#include <utility>

int T, N, K;
int map[8][8];
bool visited[8][8];
std::queue< std::pair<int,int> > q;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool boundaryCheck(int row, int col){
	if( row < 0 || row >= N || col < 0 || col >= N ) return false;
	return true;
}

void reset(){
	for(int i=0; i<8; i++) for(int j=0; j<8; j++) visited[i][j] = false;
	int qSize = q.size();
	for(int i=0; i<qSize; i++) q.pop();
}

int dfs(int row, int col, int cnt, bool isConstruction){
	int max = -1, len = -1;
	for(int k=0; k<4; k++){
		if( boundaryCheck(row + dx[k], col + dy[k]) && !visited[row + dx[k]][col + dy[k]] ){
			if( map[row + dx[k]][col + dy[k]] < map[row][col] ){
				visited[row + dx[k]][col + dy[k]] = true;
				len = dfs(row + dx[k], col + dy[k], cnt+1, isConstruction);
				visited[row + dx[k]][col + dy[k]] = false;
			} else if( !isConstruction ){
				int original = map[row + dx[k]][col + dy[k]];
				for(int construction = K; construction >= 1 && (original - construction) < map[row][col]; construction--){
					map[row + dx[k]][col + dy[k]] = original - construction;
					visited[row + dx[k]][col + dy[k]] = true;
					len = dfs(row + dx[k], col + dy[k], cnt+1, true);
					visited[row + dx[k]][col + dy[k]] = false;
				}
				map[row + dx[k]][col + dy[k]] = original;
			}
		}
		if(len > max) max = len;
	}
	if( max == -1 ) return cnt;
	return max;
}

int main(void){
	scanf("%d", &T);
	for(int round = 1; round <= T; round++){
		int maxHeight = -1;
		// input
		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				scanf("%d", &map[i][j]);
				if(maxHeight < map[i][j]) maxHeight = map[i][j];
			}
		}
		reset();

		// find the highest point
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if( map[i][j] == maxHeight ) q.push( std::make_pair(i, j) );
			}
		}

		// processing
		int max = -1;
		while( !q.empty() ){
			int row = q.front().first;
			int col = q.front().second;
			q.pop();

			visited[row][col] = true;
			int len = dfs(row, col, 1, false);
			if(max < len) max = len;
			visited[row][col] = false;
		}

		printf("#%d %d\n", round, max);
	}
	return 0;
}