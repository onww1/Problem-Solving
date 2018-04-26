#include <cstdio>
#include <queue>
#include <utility>

int r, c;
char map[50][51] = {0, };
int visited[50][50] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int boundaryCheck(int row, int col){
	if(row < 0 || row >= r || col < 0 || col >= c) return 0;
	return 1;
}

int isPossible(int row, int col){
	if(map[row][col] == 'D') return 1;
	if(map[row][col] == 'X') return 0;
	if(boundaryCheck(row + 1, col) && map[row + 1][col] == '*') return 0;
	if(boundaryCheck(row - 1, col) && map[row - 1][col] == '*') return 0;
	if(boundaryCheck(row, col + 1) && map[row][col + 1] == '*') return 0;
	if(boundaryCheck(row, col - 1) && map[row][col - 1] == '*') return 0;
	return 1;
}

int main(void){
	std::queue< std::pair<int, int> > queue_hedgehog;
	std::queue< std::pair<int, int> > queue_water;
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++)
		scanf("%s", &map[i][0]);

	// find the water and hedgehog's positions
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(map[i][j] == 'S') queue_hedgehog.push( std::make_pair(i, j) );
			if(map[i][j] == '*') queue_water.push( std::make_pair(i, j) );
		}
	}

	int cnt = 0; int flag = 0;
	while(!queue_hedgehog.empty()){
		int queue_hedgehog_size = queue_hedgehog.size();
		for(int i=0; i<queue_hedgehog_size; i++){
			int row = queue_hedgehog.front().first;
			int col = queue_hedgehog.front().second;

			if(map[row][col] == 'D'){
				flag = 1; break;
			}
			queue_hedgehog.pop();

			for(int k=0; k<4; k++){
				if(boundaryCheck(row + dx[k], col + dy[k]) && !visited[row + dx[k]][col + dy[k]] && isPossible(row + dx[k], col + dy[k])){
					visited[row + dx[k]][col + dy[k]] = 1;
					queue_hedgehog.push( std::make_pair(row + dx[k], col + dy[k]) );
				}
			}
		}
		if(flag) break;
		cnt++;

		int queue_water_size = queue_water.size();
		for(int i=0; i<queue_water_size; i++){
			int row = queue_water.front().first;
			int col = queue_water.front().second;
			queue_water.pop();

			for(int k=0; k<4; k++){
				if(boundaryCheck(row + dx[k], col + dy[k]) && map[row + dx[k]][col + dy[k]] == '.'){
					map[row + dx[k]][col + dy[k]] = '*';
					queue_water.push( std::make_pair(row + dx[k], col + dy[k]) );
				}
			}
		}
	}

	if(queue_hedgehog.empty()) printf("KAKTUS\n");
	else printf("%d\n", cnt);
	return 0;
}