#include <cstdio>

int dp[13];

void reset(){
	for(int i=0; i<=12; i++){
		dp[i] = 0;
	}
}

int min(int a, int b){
	return a<b?a:b;
}

int main(void){
	int T;
	int cost[4];
	int month[13] = {0, };

	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		for(int i=0; i<4; i++) scanf("%d", &cost[i]);
		for(int i=1; i<=12; i++) scanf("%d", &month[i]);
		reset();
		dp[12] = cost[3];

		for(int i=1; i<=12; i++){
			if(i<3){
				dp[i] = min( dp[i-1] + min( cost[0] * month[i], cost[1] ), cost[2] );
			} else if(i<12){
				dp[i] = min( dp[i-1] + min( cost[0] * month[i], cost[1] ), dp[i-3] + cost[2] );
			} else {
				dp[i] = min( dp[i], min( dp[i-1] + min( cost[0] * month[i], cost[1] ), dp[i-3] + cost[2] ) );
			}
		}

		printf("#%d %d\n", t, dp[12]);
	}

	return 0;
}