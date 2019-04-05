#include <cstdio>
#include <queue>

int main(void){
	int t, m, n, k, x, y, cnt, arr[50][50], visited[50][50];
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0,  0, 1,-1};
	std::queue< std::pair<int,int> > q;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &m, &n, &k);
		for(int i=0; i<n; i++) for(int j=0; j<m; j++) {arr[i][j] = 0; visited[i][j] = 0;}
		cnt = 0;
		for(int i=0; i<k; i++){
			scanf("%d %d", &x, &y);
			arr[y][x] = 1;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j] == 0 || visited[i][j] == 1) continue;
				else {
					q.push(std::make_pair(i, j));
					visited[i][j] = 1;
					while(!q.empty()){
						y = q.front().first;
						x = q.front().second;
						q.pop();
						visited[y][x] = 1;
						for(int z=0; z<4; z++)
							if( y+dy[z] >= 0 && y+dy[z] < n && x+dx[z] >= 0 && x+dx[z] < m &&
								arr[y+dy[z]][x+dx[z]] == 1 && visited[y+dy[z]][x+dx[z]] == 0){
								q.push(std::make_pair(y+dy[z], x+dx[z])); 
								visited[y+dy[z]][x+dx[z]] = 1;
							}
					}
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}