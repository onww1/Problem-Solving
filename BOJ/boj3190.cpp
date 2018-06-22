#include <cstdio>
#include <queue>
#include <utility>

int N, K, L, r, c, x = 0, tx = 0;
char d, td;
char map[101][101] = {0, };
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
std::queue< std::pair<int,char> > q;

int main(void){
	scanf("%d", &N);
	scanf("%d", &K);
	while(K--){
		scanf("%d %d", &r, &c);
		map[r][c] = 2;
	}
	scanf("%d", &L);

	int hdirection = 0, tdirection = 0;
	int hr = 1, hc = 1, tr = 1, tc = 1, t = 0, tt = 0;
	map[hr][hc] = 1;
	while(1){
		if(L && t>=x) { 
			scanf("%d %c", &x, &d); 
			q.push( std::make_pair(x, d) );
			L--;
		}
		t++;
		hr += dx[hdirection];
		hc += dy[hdirection];
		// printf("t : %d\nx : %d\nd : %d\nL : %d\n", t, x, d, L);
		// for(int i=1; i<=N; i++){
		// 	for(int j=1; j<=N; j++){
		// 		printf("%d", map[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		if(hr <= 0 || hr > N || hc <= 0 || hc > N || map[hr][hc] == 1){
			printf("%d\n", t);
			break;
		}
		
		if(!q.empty() && tt>=tx) {
			tx = q.front().first;
			td = q.front().second;
			q.pop();
		}

		if(!map[hr][hc]){
			map[tr][tc] = 0;
			tt++;
			tr += dx[tdirection];
			tc += dy[tdirection];
		}
		map[hr][hc] = 1;


		if(tt>=tx){
			if(td == 'D'){ tdirection = (tdirection + 1)%4; }
			else if(td == 'L'){ tdirection = (tdirection + 3)%4; }
			td = 0;
		}
		if(t>=x){
			if(d == 'D'){ hdirection = (hdirection + 1)%4; }
			else if(d == 'L'){ hdirection = (hdirection + 3)%4; }
			d = 0;
		}
	}

	return 0;
}
