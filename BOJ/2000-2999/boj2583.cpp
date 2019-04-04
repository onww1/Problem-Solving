#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

int map[100][100] = {0, };
int visited[100][100] = {0, };
int dx[4] = {0, 0, 1,-1};
int dy[4] = {1,-1, 0, 0};

int check(int row, int col, int rnum, int cnum){
	if(row < 0 || row >= rnum || col < 0 || col >= cnum) return 0;
	return 1;
}

int main(void){
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);

	int r1, c1, r2, c2;
	for(int i=0; i<k; i++){
		scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
		for(int row = r1; row < r2; row++){
			for(int col = c1; col < c2; col++){
				map[row][col] = 1;
			}
		}
	}

	std::queue< std::pair<int,int> > q;
	std::vector<int> vec;
	int num = 0, cnt = 0;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 1 || visited[i][j]) continue;
			q.push( std::make_pair(i, j) );
			num++; cnt=1;
			visited[i][j] = 1;
			map[i][j] = num;
			
			while(!q.empty()){
				int row = q.front().first;
				int col = q.front().second;
				q.pop();

				for(int k=0; k<4; k++){
					if(check(row + dx[k], col + dy[k], m, n) 
					&& map[row + dx[k]][col + dy[k]] == 0
					&& !visited[row + dx[k]][col + dy[k]]){
						q.push( std::make_pair(row + dx[k], col + dy[k]) );
						visited[row + dx[k]][col + dy[k]] = 1;
						map[row + dx[k]][col + dy[k]] = num;
						cnt++;
					}
				}
			}

			vec.push_back(cnt);
		}
	}
	
	std::sort(vec.begin(), vec.end());
	printf("%d\n", num);
	for(auto it = vec.begin(); it != vec.end(); it++){
		printf("%d ", *it);
	}
	printf("\n");
	return 0;
}