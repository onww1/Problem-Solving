#include <cstdio>
#include <queue>
#include <utility>

int map[100][100] = {0, };
int visited[100][100] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n;
int check(int row, int col){
	if(row < 0 || row >= n || col < 0 || col >= n) return 0;
	return 1;
}

int main(void){
	int maxHeight = 0, minHeight = 10000, maxNum = 1, cnt;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] > maxHeight) maxHeight = map[i][j];
			if(map[i][j] < minHeight) minHeight = map[i][j];
		}
	}

	for(int height = minHeight; height < maxHeight; height++){
		std::queue< std::pair<int,int> > q;
		cnt = 0;

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(map[i][j] <= height) visited[i][j] = 1;
				else visited[i][j] = 0;
			}
		}

		// printf("\n-------- height : %d --------\n", height);
		// for(int i=0; i<n; i++){
		// 	for(int j=0; j<n; j++){
		// 		printf("%d ", visited[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(!visited[i][j]){
					visited[i][j] = 1;
					q.push( std::make_pair(i, j) );
					cnt++;

					while(!q.empty()){
						int row = q.front().first;
						int col = q.front().second;
						q.pop();

						for(int k=0; k<4; k++){
							if(check(row + dx[k], col + dy[k])
							&& !visited[row + dx[k]][col + dy[k]]){
								visited[row + dx[k]][col + dy[k]] = 1;
								q.push( std::make_pair(row + dx[k], col + dy[k]) );
							}
						}
					}
				}
			}
		}

		// printf("num of safe area is %d.\n", cnt);
		// printf("---------------------------\n");
		if(cnt > maxNum) maxNum = cnt;
	}

	printf("%d\n", maxNum);
	return 0;
}