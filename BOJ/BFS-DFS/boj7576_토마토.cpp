#include <cstdio>
#include <queue>
#include <utility>

int map[1001][1001] = {0, };
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

int check(int row, int col, int n, int m){
	if(row < 1 || row > n || col < 1 || col > m){
		return 0;
	}
	return 1;
}

int main(void){
	int m, n, numOfZeros = 0, cnt=0;
	std::queue< std::pair<int,int> > q;

	scanf("%d %d", &m, &n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &map[i][j]);
			if(!map[i][j]) numOfZeros++;
		}
	}
	if(!numOfZeros) printf("0\n");
	else {
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(map[i][j] == 1) {
					q.push( std::make_pair(i, j) );
				}
			}
		}

		while(!q.empty()){
			std::queue< std::pair<int,int> > temp;
			while(!q.empty()){
				temp.push( q.front() );
				q.pop();
			}
			cnt++;
			while(!temp.empty()){
				int row = temp.front().first;
				int col = temp.front().second;
				temp.pop();

				for(int i=0; i<4; i++){
					if(check(row + dx[i], col + dy[i], n, m) && map[row + dx[i]][col + dy[i]] == 0){
						map[row + dx[i]][col + dy[i]] = 1;
						numOfZeros--;
						q.push( std::make_pair( row + dx[i], col + dy[i] ) );
					}
				}

			}
		}
		cnt--;
		if(numOfZeros > 0) printf("-1\n");
		else printf("%d\n", cnt);
	}
	
	return 0;
}