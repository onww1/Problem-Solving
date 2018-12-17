#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, A[100000];
	cin >> N;
	for (int i=0; i<N; ++i) cin >> A[i];

	sort(A, A+N);
	
	int prev = -10000;
	for (int i=0; i<N; ++i) {
		if (A[i] != prev) {
			cout << A[i] << ' ';
			prev = A[i];
		}
	}
	cout << '\n';
	return 0;
}