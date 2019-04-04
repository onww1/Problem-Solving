#include <iostream>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	if(N < M) {
		int tmp = N;
		N = M;
		M = tmp;
	}
	
	int dp[301][301] = { 0, };
	dp[1][1] = 0;
	dp[2][1] = dp[1][2] = 1;
	dp[2][2] = 1 + dp[2][1] + dp[2][1];
	
	for(int i=3; i<=N; i++){
		for(int j=1; j<=i; j++){
			int min = 987654321;
			for(int a=1; a<=i/2; a++){
				min = min > dp[a][j] + dp[i-a][j] ? dp[a][j] + dp[i-a][j] : min;	
			}
			for(int b=1; b<=j/2; b++){
				min = min > dp[i][b] + dp[i][j-b] ? dp[i][b] + dp[i][j-b] : min;
			}
			
			dp[i][j] = dp[j][i] = 1 + min;
		}
	}
	
	cout << dp[N][M] << '\n';
	
	return 0;
}

