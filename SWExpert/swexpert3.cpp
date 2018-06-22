#include <cstdio>
#include <queue>
#include <utility>

int T, N, M, R, C, L;
char map[50][50];
bool visited[50][50];

void init(){
	scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%hhd", &map[i][j]);
			visited[i][j] = false;
		}
	}	
}

int main(void){
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int count = 1;
		init();
		std::queue< std::pair< std::pair<int,int>, int> > q;
		visited[R][C] = true;
		q.push( std::make_pair( std::make_pair(R, C), 1) );
		while( !q.empty() ){
			int row = q.front().first.first;
			int col = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			if( cnt == L ) break;

			if( row > 0 && !visited[row-1][col] && (map[row][col] == 1 || map[row][col] == 2 || map[row][col] == 4 || map[row][col] == 7) ){
				if(map[row-1][col] == 1 || map[row-1][col] == 2 || map[row-1][col] == 5 || map[row-1][col] == 6){
					visited[row-1][col] = true;
					q.push( std::make_pair( std::make_pair(row-1, col), cnt+1) );
					count++;
				}
			}
			if( row < N - 1 && !visited[row+1][col] && (map[row][col] == 1 || map[row][col] == 2 || map[row][col] == 5 || map[row][col] == 6) ){
				if(map[row+1][col] == 1 || map[row+1][col] == 2 || map[row+1][col] == 4 || map[row+1][col] == 7){
					visited[row+1][col] = true;
					q.push( std::make_pair( std::make_pair(row+1, col), cnt+1) );
					count++;
				}
			}
			if( col > 0 && !visited[row][col-1] && (map[row][col] == 1 || map[row][col] == 3 || map[row][col] == 6 || map[row][col] == 7) ){
				if(map[row][col-1] == 1 || map[row][col-1] == 3 || map[row][col-1] == 4 || map[row][col-1] == 5){
					visited[row][col-1] = true;
					q.push( std::make_pair( std::make_pair(row, col-1), cnt+1) );
					count++;
				}
			}
			if( col < M - 1 && !visited[row][col+1] && (map[row][col] == 1 || map[row][col] == 3 || map[row][col] == 4 || map[row][col] == 5) ){
				if(map[row][col+1] == 1 || map[row][col+1] == 3 || map[row][col+1] == 6 || map[row][col+1] == 7){
					visited[row][col+1] = true;
					q.push( std::make_pair( std::make_pair(row, col+1), cnt+1) );
					count++;
				}
			}
		}
		printf("#%d %d\n", t, count);
	}
	return 0;
}