#include <cstdio>
#include <queue>
#include <utility>

int map[300][300] = {0, };
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int check(int row, int col, int l){
	if(row < 0 || row >= l || col < 0 || col >= l) return 0;
	return 1;
}

int main(void){
	int t, l, sr, sc, dr, dc;
	scanf("%d", &t);

	for(;t--;){
		scanf("%d", &l);
		scanf("%d %d", &sr, &sc);
		scanf("%d %d", &dr, &dc);
		std::queue< std::pair<std::pair<int,int>, int> > q;
		
		for(int i=0; i<l; i++)
			for(int j=0; j<l; j++)
				map[i][j] = 100000;

		map[sr][sc] = 0;
		q.push( std::make_pair( std::make_pair(sr, sc), map[sr][sc]) );

		while(!q.empty()){
			std::pair<int,int> data = q.front().first;
			int row = data.first;
			int col = data.second;
			int val = q.front().second;
			q.pop();

			if(row == dr && col == dc){
				break;
			}

			for(int i=0; i<8; i++){
				if( check( row + dx[i], col + dy[i], l )
				 && map[row + dx[i]][col + dy[i]] > val + 1){
					map[row + dx[i]][col + dy[i]] = val + 1;
					q.push( std::make_pair( std::make_pair(row + dx[i], col + dy[i]), val + 1) );
				}
			}
		}

		printf("%d\n", map[dr][dc]);
	}

	return 0;
}