#include <stdio.h>

int main(void){
	int t;
	scanf("%d", &t);

	int M, N, x, y;
	long long cnt;
	while(t--){
		scanf("%d %d %d %d", &M, &N, &x, &y);
		cnt = (long long)y;
		int tmpX = (y%M == 0)?M:y%M, i = 0;
		for(i = 0; i < M; i++){
			if(tmpX == x) break;
			if((tmpX+N)%M == 0) tmpX = M;
			else tmpX = (tmpX+N)%M;
			cnt += (long long)N;
		}
		if(i == M) printf("-1\n");
		else printf("%lld\n", cnt);
	}
	return 0;
}