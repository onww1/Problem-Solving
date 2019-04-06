#include <cstdio>
#include <queue>

int F, S, G, U, D;
int dp[1000001] = {0, };

int main(void){
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	std::queue<int> q;
	int cnt = -1;

	q.push(S);
	dp[S] = 1;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(cur == G){
			cnt = dp[cur] - 1;
			break;
		}

		if(cur+U <= F && dp[cur+U] == 0){
			dp[cur+U] = dp[cur] + 1;
			q.push(cur+U);
		}
		if(cur-D >= 1 && dp[cur-D] == 0){
			dp[cur-D] = dp[cur] + 1;
			q.push(cur-D);
		}
	}

	if(cnt == -1) printf("use the stairs\n");
	else printf("%d\n", cnt);
	return 0;
}