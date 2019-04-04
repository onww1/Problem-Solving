#include <iostream>
using namespace std;

int max(int a, int b){return a>b?a:b;}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, A[10000], dp[10000][2];
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> A[i];

	dp[0][0] = 0; 
	dp[0][1] = A[0];
	dp[1][0] = A[0]; 
	dp[1][1] = A[0] + A[1];
	for(int i=2; i<N; i++){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = max(dp[i-2][0] + A[i-1], dp[i-1][0]) + A[i];
	}

	cout << max(dp[N-1][0], dp[N-1][1]) << '\n';
	return 0;
}