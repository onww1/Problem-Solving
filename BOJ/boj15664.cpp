#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[8];
vector<int> vec;

void dfs(int t, int idx) {
	if (t == M) {
		cout << vec[0];
		for (int i=1; i<vec.size(); i++) {
			cout << ' ' << vec[i];
		}
		cout << '\n';
		return;
	}

	for (int i=idx+1; i<=N-M+t; i++) {
		if (i == idx+1 || A[i-1] != A[i]) {
			vec.push_back(A[i]);
			dfs(t + 1, i);
			vec.pop_back();
		}
	}
}

int main() {	
	cin >> N >> M;
	for (int i=0; i<N; i++)
		cin >> A[i];

	sort(A, A+N);

	for (int i=0; i<=N-M; i++) {
		if (i == 0 || A[i-1] != A[i]) {
			vec.push_back(A[i]);
			dfs(1, i);
			vec.pop_back();
		}
	}

	return 0;
}