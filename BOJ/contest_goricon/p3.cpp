#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, A[10], dp[1001][10] = { 0, };
	vector<int> vec;
	
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> dp[i][0];
		for (int j=1; j<=dp[i][0]; j++) {
			cin >> A[j];
		}
	}

	return 0;
}