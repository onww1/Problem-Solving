#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

int n, m, zeros = 0;
char map[8][8] = {0, };
char visited[8][8] = {0, };
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
std::vector< std::pair<int,int> > virus;

int boundaryCheck(int row, int col){
	if(row < 0 || row >= n || col < 0 || col >= m) return 0;
	return 1;
}

void reset(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			visited[i][j] = map[i][j];
		}
	}
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%hhd", &map[i][j]);
			if(map[i][j] == 2) virus.push_back( std::make_pair(i,j) );
			else if(map[i][j] == 0) zeros++;
		}
	}
	zeros -= 3;

	std::queue< std::pair<int, int> > q;
	int max = 0, cnt = 0;
	for(int r1=0; r1<n; r1++){
		for(int c1=0; c1<m; c1++){
			if(map[r1][c1]) continue;
			map[r1][c1] = 1;

			for(int r2=r1; r2<n; r2++){
				for(int c2=0; c2<m; c2++){
					if(r2 * n + c2 <= r1 * n + c1 || map[r2][c2]) continue;
					map[r2][c2] = 1;

					for(int r3=r2; r3<n; r3++){
						for(int c3=0; c3<m; c3++){
							if(r3 * n + c3 <= r2 * n + c2 || map[r3][c3]) continue;
							map[r3][c3] = 1;

							cnt = 0;
							reset();
							int vec_size = virus.size();
							for(int i=0; i<vec_size; i++) q.push( virus[i] );
							while(!q.empty()){
								int row = q.front().first;
								int col = q.front().second;
								q.pop();

								for(int k=0; k<4; k++){
									if(boundaryCheck(row + dx[k], col + dy[k]) && !visited[row + dx[k]][col + dy[k]]){
										visited[row + dx[k]][col + dy[k]] = 2;
										cnt++;
										q.push( std::make_pair(row + dx[k], col + dy[k]) );
									}
								}
							}
							if( zeros - cnt > max ) max = zeros - cnt;
							map[r3][c3] = 0;
						}
					}
					map[r2][c2] = 0;
				}
			}
			map[r1][c1] = 0;
		}
	}

	printf("%d\n", max);
	return 0;
}