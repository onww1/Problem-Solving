#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int V[100], dp[10001] = {0, };

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> V[i];
		dp[V[i]] = 1;
	}

	sort(V, V+N);

	for(int i=1; i<=K; i++){
		for(int j=N-1; j>=0; j--){
			if(V[j] < i && i - V[j] > i/2){
				dp[i] += dp[i-V[j]];
			}
		}
	}

	cout << dp[K] << '\n';

	return 0;
}