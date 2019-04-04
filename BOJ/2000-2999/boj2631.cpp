#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, A[200];
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> A[i];

	vector<int> lis;
	lis.push_back(A[0]);

	for (int i=1; i<N; i++) {
		auto idx = lower_bound(lis.begin(), lis.end(), A[i]);
		if (idx == lis.end()) lis.push_back(A[i]);
		else *idx = A[i];
	}

	cout << (N - lis.size()) << '\n';

	return 0;
}