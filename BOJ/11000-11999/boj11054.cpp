#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A(N);
	for (int i=0; i<N; ++i) cin >> A[i];

	vector<int> inc(N, 1), rinc(N, 1);
	for (int i=1; i<N; ++i) {
		int max = 0, rmax = 0;
		for (int j=i-1; j>=0; j--) {
			if (A[i] > A[j] && inc[j] > max) max = inc[j];
			if (A[N-1-i] > A[N-1-j] && rinc[N-1-j] > rmax) rmax = rinc[N-1-j];
		}
		inc[i] += max;
		rinc[N-1-i] += rmax;
	}
	
	int max = 0;
	for (int i=0; i<N; i++) 
		max = max < (inc[i] + rinc[i]) ? inc[i] + rinc[i] : max;
	
	cout << (max - 1) << '\n';
	return 0;
}