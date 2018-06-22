#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>

int n;
int map[100][100] = {0, };
int visited[100][100] = {0, };
int region[100][100] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int boundaryCheck(int row, int col){
	if(row < 0 || row >= n || col < 0 || col >= n) return 0;
	return 1;
}

int main(void){
	int num = 1;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}

	std::queue< std::pair<int,int> > q;

	// numbering
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(visited[i][j] || !map[i][j]) continue;
			if(map[i][j]){
				q.push( std::make_pair(i, j) );
				visited[i][j] = 1;
				region[i][j] = num;
			}
			while(!q.empty()){
				int row = q.front().first;
				int col = q.front().second;
				q.pop();

				for(int k=0; k<4; k++){
					if( boundaryCheck(row + dx[k], col + dy[k])
					 && !visited[row + dx[k]][col + dy[k]]
					 && map[row + dx[k]][col + dy[k]]){
						q.push( std::make_pair(row + dx[k], col + dy[k]) );
						visited[row + dx[k]][col + dy[k]] = 1;
						region[row + dx[k]][col + dy[k]] = num;
					}
				}
			}
			num++;
		}
	}

	// reset the visited array
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) visited[i][j] = 0;
	
	// find contours
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] && map[i][j] != -1){
				visited[i][j] = 1;
				for(int k=0; k<4; k++){
					if( boundaryCheck(i + dx[k], j + dy[k])
					 && !map[i + dx[k]][j + dy[k]] 
					 && !visited[i + dx[k]][j + dy[k]]){
						q.push( std::make_pair(i + dx[k], j + dy[k]) );
						visited[i + dx[k]][j + dy[k]] = 1;
						region[i + dx[k]][j + dy[k]] = region[i][j];
						map[i + dx[k]][j + dy[k]] = -1;
					}
					if(visited[i + dx[k]][j + dy[k]] && region[i + dx[k]][j + dy[k]] != region[i][j]){
						printf("%d\n", 1);
						exit(0);
					}
				}
			}
		}
	}

	for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(map[i][j] == -1) map[i][j] = 1;

	// calculate mininum length of bridge
	int cnt = 1;
	while(!q.empty()){
		cnt++;
		int qSize = q.size();
		for(int i=0; i<qSize; i++){
			int row = q.front().first;
			int col = q.front().second;
			int reg = region[row][col];
			q.pop();

			for(int k=0; k<4 && boundaryCheck(row + dx[k], col + dy[k]); k++){
				if( !visited[row + dx[k]][col + dy[k]]){
					q.push( std::make_pair(row + dx[k], col + dy[k]) );
					visited[row + dx[k]][col + dy[k]] = 1;
					map[row + dx[k]][col + dy[k]] = cnt;
					region[row + dx[k]][col + dy[k]] = region[row][col];
				}
				if(visited[row + dx[k]][col + dy[k]] && region[row + dx[k]][col + dy[k]] != region[row][col]){
					printf("%d\n", map[row + dx[k]][col + dy[k]] + cnt - 1);
					exit(0);
				}
			}
		}

		cnt++;
	}

	return 0;
}