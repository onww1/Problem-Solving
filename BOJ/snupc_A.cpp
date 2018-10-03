#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K, A[300000];
	cin >> N >> K;

	for(int i=0; i<N; i++)
		cin >> A[i];

	sort(A, A+N);
	
	long long sum = 0LL;
	for(int i=0; i<N; i++){
		if(i < K) sum += ((long long)A[i] * (long long)i);
		else sum += ((long long)A[i] * (long long)K);
	}

	cout << sum << '\n';

	return 0;
}