#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, A[1000];
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> A[i];

	vector<int> lds;
	lds.push_back(A[N-1]);

	for (int i=N-2; i>=0; i--) {
		auto it = lower_bound(lds.begin(), lds.end(), A[i]);
		if (it == lds.end()) lds.push_back(A[i]);
		else *it = A[i];
	}

	cout << lds.size() << '\n';

	return 0;
}