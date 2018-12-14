#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> A(N);
	for (int i=0; i<N; ++i) cin >> A[i];

	sort(A.begin(), A.end());

	cout << A[K-1] << '\n';
	return 0;
}