#include <iostream>
using namespace std;

int max(int a, int b){ return a>b?a:b; }
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, A[100000];
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> A[i];

	int dp[100000];
	dp[0] = max(0, A[0]);

	int max_val = A[0];
	for(int i=1; i<N; i++){
		dp[i] = max(dp[i-1] + A[i], A[i]);
		max_val = max(max_val, dp[i]);
		if(max_val <= 0 && A[i] < 0)
			max_val = max(max_val, A[i]);
	}

	cout << max_val << '\n';
	return 0;
}