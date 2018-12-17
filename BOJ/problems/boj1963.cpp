#include <cstdio>
#include <queue>
#include <utility>

int prime[10000] = {0, 0, 1, };
int visited[10000] = {0, };
int power[4] = {1, 10, 100, 1000};

int check(int num){
	if(num/1000 == 0) return 0;
	return 1;
}

void reset_visited(void){
	for(int i=1000; i<10000; i++) visited[i] = 0;
}

int main(void){
	int t, src, dst;

	// make prime table
	for(int i=2; i<10000; i++) prime[i] = 1;
	for(int i=2; i<10000; i++){
		if(prime[i]){
			for(int j = i*2; j<10000; j += i){
				prime[j] = 0;
			}
		}
	}

	scanf("%d", &t);
	while(t--){
		std::queue< std::pair<int,int> > q;
		reset_visited();

		scanf("%d %d", &src, &dst);
		q.push( std::make_pair(src, 0) );
		visited[src] = 1;

		while(!q.empty()){
			int val = q.front().first;
			int cnt = q.front().second;
			if( val == dst ) {
				printf("%d\n", cnt);
				break;
			}
			q.pop();

			for(int i=0; i<4; i++){
				int temp = val - ((val%(power[i]*10))/power[i])*power[i];
				for(int j=0; j<10; j++){
					int v = temp + power[i] * j;
					if( prime[v] && check(v) && !visited[v] ){
						q.push( std::make_pair( v, cnt + 1) );
						visited[v] = 1;
					}
				}
			}
		}
		if(q.empty()) printf("Impossible\n");
	}

	return 0;
}