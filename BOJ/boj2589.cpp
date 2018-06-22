#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#define INF 10000

char input[50][50] = {0, };
int map[50][50] = {0, };
int visited[50][50] = {0, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int row, col;

int boundaryCheck(int i, int j){
	if(i < 0 || i >= row || j < 0 || j >= col) return 0;
	return 1;
}

int leafCheck(int i, int j){
	int count = 0;
	if(boundaryCheck(i+1, j) && input[i+1][j] == 'L') count++;
	if(boundaryCheck(i-1, j) && input[i-1][j] == 'L') count++;
	if(boundaryCheck(i, j+1) && input[i][j+1] == 'L') count++;
	if(boundaryCheck(i, j-1) && input[i][j-1] == 'L') count++;
	if(count == 1) return 1;
	return 0;
}

void init_visited(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(input[i][j] == 'W') visited[i][j] = 1;
			else visited[i][j] = 0;
		}
	}
}

int main(void){
	std::queue< std::pair<int,int> > leafs;
	
	int localMax = 0, globalMax = 0;
	scanf("%d %d", &row, &col);
	for(int i=0; i<row; i++){
		scanf("%s", &input[i][0]);
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(input[i][j] == 'W') map[i][j] = INF;
			else {
				map[i][j] = 0;
				if(leafCheck(i, j)) leafs.push( std::make_pair(i, j) );
			}
		}
	}

	if(leafs.empty()){
		std::queue< std::pair<int,int> > q;
		init_visited();
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				if(!visited[i][j]){
					q.push( std::make_pair(i, j) );
					visited[i][j] = 1;
					map[i][j] = 0;

					while(!q.empty()){
						int r = q.front().first;
						int c = q.front().second;
						q.pop();

						for(int k=0; k<4; k++){
							if(boundaryCheck(r + dx[k], c + dy[k]) && !visited[r + dx[k]][c + dy[k]]){
								visited[r + dx[k]][c + dy[k]] = 1;
								map[r + dx[k]][c + dy[k]] = map[r][c] + 1;
								q.push( std::make_pair( r+dx[k], c+dy[k]) );
								if( map[r][c] + 1 > globalMax ) globalMax = map[r][c] + 1;
							}
						}
					}
				}
			}
		}
	} else {
		while(!leafs.empty()){
			std::queue< std::pair<int,int> > q;
			init_visited();
			int r = leafs.front().first;
			int c = leafs.front().second;
			leafs.pop();
			
			localMax = 0;

			q.push( std::make_pair(r, c) );
			visited[r][c] = 1;
			map[r][c] = 0;

			while(!q.empty()){
				r = q.front().first;
				c = q.front().second;
				q.pop();

				for(int i=0; i<4; i++){
					if(boundaryCheck(r + dx[i], c + dy[i]) && !visited[r + dx[i]][c + dy[i]]){
						visited[r + dx[i]][c + dy[i]] = 1;
						map[r + dx[i]][c + dy[i]] = map[r][c] + 1;
						if(map[r][c] + 1 > localMax) localMax = map[r][c] + 1;
						q.push( std::make_pair(r + dx[i], c + dy[i]) );
					}
				}
			}

			if(localMax > globalMax) globalMax = localMax;
		}	
	}


	printf("%d\n", globalMax);
	return 0;
}