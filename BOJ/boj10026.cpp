#include <cstdio>
#include <queue>
#include <utility>

char map[100][101] = {0, };
int visited[100][100] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

int boundaryCheck(int row, int col){
	if( row < 0 || row >= n || col < 0 || col >= n ) return 0;
	return 1;
}

int disable(char src, char dst){
	if(src == 'B' && dst == 'B') return 1;
	else if( (src == 'R' || src == 'G') && (dst == 'R' || dst == 'G') ) return 1;
	return 0;
}

int main(void){
	int num1 = 0, num2 = 0;
	std::queue< std::pair<int, int> > q;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s", &map[i][0]);
	}

	// count non disable
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(visited[i][j]) continue;
			q.push( std::make_pair(i, j) );
			visited[i][j] = 1;
			while(!q.empty()){
				int row = q.front().first;
				int col = q.front().second;
				q.pop();

				for(int k=0; k<4; k++){
					if(boundaryCheck(row + dx[k], col + dy[k]) && !visited[row + dx[k]][col + dy[k]] && map[row][col] == map[row + dx[k]][col + dy[k]]){
						q.push( std::make_pair(row + dx[k], col + dy[k]) );
						visited[row + dx[k]][col + dy[k]] = 1;
					}
				}
			}
			num1++;
		}
	}

	for(int i=0; i<n; i++) for(int j=0; j<n; j++) visited[i][j] = 0;

	// count disable
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(visited[i][j]) continue;
			q.push( std::make_pair(i, j) );
			visited[i][j] = 1;
			while(!q.empty()){
				int row = q.front().first;
				int col = q.front().second;
				q.pop();

				for(int k=0; k<4; k++){
					if(boundaryCheck(row + dx[k], col + dy[k]) && !visited[row + dx[k]][col + dy[k]] && disable(map[row][col], map[row + dx[k]][col + dy[k]]) ){
						q.push( std::make_pair(row + dx[k], col + dy[k]) );
						visited[row + dx[k]][col + dy[k]] = 1;
					}
				}
			}
			num2++;
		}
	}

	printf("%d %d\n", num1, num2);
	return 0;
			
}