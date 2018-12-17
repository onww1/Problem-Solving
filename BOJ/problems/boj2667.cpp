#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

int map[25][25] = {0, };
int visited[25][25] = {0, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int check(int row, int col, int n){
	if(row < 0 || row >= n || col < 0 || col >= n)
		return 0;
	return 1;
}

int main(void){
	int n, num = 1, cnt = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d", &map[i][j]);
		}
	}

	std::queue< std::pair<int,int> > q;
	std::vector<int> vec;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 1 && !visited[i][j]){
				cnt = 1;
				q.push( std::make_pair(i, j) );
				visited[i][j] = 1;
				map[i][j] = num;

				while(!q.empty()){
					int row = q.front().first;
					int col = q.front().second;
					q.pop();

					for(int k=0; k<4; k++){
						if(check(row + dx[k], col + dy[k], n) && map[row + dx[k]][col + dy[k]] == 1 && !visited[row + dx[k]][col + dy[k]]){
							map[row + dx[k]][col + dy[k]] = num;
							visited[row + dx[k]][col + dy[k]] = 1;
							q.push( std::make_pair(row + dx[k], col + dy[k]) );
							cnt++;
						}
					}
				}

				num++;
				vec.push_back(cnt);
			}
		}
	}

	printf("%d\n", --num);
	std::sort(vec.begin(), vec.end());
	for(auto it = vec.begin(); it != vec.end(); it++){
		printf("%d\n", *it);
	}

	
	return 0;
}