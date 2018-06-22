#include <cstdio>
#include <queue>
#include <utility>

int n, m;
char map[1000][1001] = {0, };
int visited[1000][1000][2] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int boundaryCheck(int row, int col){
	if(row < 0 || row >= n || col < 0 || col >= m) return 0;
	return 1;
}

int main(void){
	// input data
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%s", map[i]);
	}

	std::queue< std::pair< std::pair<int, int>, int> > q;
	q.push( std::make_pair( std::make_pair(0, 0), 0 ) );
	visited[0][0][0] = 1;

	while(!q.empty()){
		int row = q.front().first.first;
		int col = q.front().first.second;
		int flag = q.front().second;
		q.pop();

		for(int k=0; k<4; k++){
			if( boundaryCheck(row + dx[k], col + dy[k]) ){
				if( map[row + dx[k]][col + dy[k]] == '0' && !visited[row + dx[k]][col + dy[k]][flag] ){
					visited[row + dx[k]][col + dy[k]][flag] = visited[row][col][flag] + 1;
					q.push( std::make_pair( std::make_pair(row + dx[k], col + dy[k]), flag) );
				} else if( map[row + dx[k]][col + dy[k]] == '1' && !flag){
					visited[row + dx[k]][col + dy[k]][1] = visited[row][col][0] + 1;
					q.push( std::make_pair( std::make_pair(row + dx[k], col + dy[k]), 1) );
				}
			}
		}
	}

	int result;
	if(visited[n-1][m-1][0] == 0 && visited[n-1][m-1][1] == 0) result = -1;
	else if(visited[n-1][m-1][0] == 0 && visited[n-1][m-1][1]) result = visited[n-1][m-1][1];
	else if(visited[n-1][m-1][1] == 0 && visited[n-1][m-1][0]) result = visited[n-1][m-1][0];
	else result = (visited[n-1][m-1][0] > visited[n-1][m-1][1])?visited[n-1][m-1][1]:visited[n-1][m-1][0];

	printf("%d\n", result);	
	return 0;
}