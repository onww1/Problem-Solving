#include <iostream>
using namespace std;

int MAX(int a, int b){return a>b?a:b;}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, P[1001], dp[1001][1001] = {0, }, M[1001];
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> P[i];

	dp[0][0] = 0;
	for(int i=1; i<=N; i++)
		dp[0][i] = dp[i][0] = P[i];
	M[0] = 0;
	M[1] = P[1];

	for(int k=2; k<=N; k++){
		int max = P[k], i = 1;
		while(i > 0 && k - i > 0){
			dp[i][k - i] = M[i] + M[k - i];
			max = MAX(max, dp[i][k-i]);
			i++;
		}
		M[k] = max;
	}

	cout << M[N] << '\n';

	return 0;
}