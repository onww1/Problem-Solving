#include <iostream>
using namespace std;

int N, M;
int map[1000][1000];
int dp[1000][1000] = {0, };
int dp2[1000][1000][2] = {0, };

int get_dp(int r, int c){
	if(r < 0 || r >= N || c < 0 || c >= M) return 0;
	return dp[r][c];
}

int get_dp2(int r, int c, int d){
	if(r < 0 || r >= N || c < 0 || c >= M) return 0;
	return dp2[r][c][d];
}

int get_val(int r, int c){
	if(r < 0 || r >= N || c < 0 || c >= M) return 0;
	return map[r][c];
}

int max3(int a, int b, int c){
	return a>b?(a>c?a:c):(b>c?b:c);
}

int max2(int a, int b){
	return a>b?a:b;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> map[i][j];

	for(int j=0; j<M; j++){
		for(int i=0; i<N; i++){
			dp[i][j] = map[i][j] + max3(
				get_dp(i-1, j-1), 
				get_dp(i+1, j-1), 
				get_val(i, j-1) + get_dp(i, j-2)
				);

			dp2[i][j][0] = map[i][j] + max2(get_dp2(i, j-1, 1), get_dp2(i-1, j-1, 0));
			dp2[i][j][1] = map[i][j] + max2(get_dp2(i, j-1, 0), get_dp2(i+1, j-1, 1));
		}
	}

	int max_num = -1;
	for(int i=0; i<N; i++){
		int temp = max3(dp[i][M-1], dp2[i][M-1][0], dp2[i][M-1][1]);
		if(max_num < temp) max_num = temp;
	}

	cout << max_num << '\n';
	return 0;
}