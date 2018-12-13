#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& A, int& S, int &cnt, int& sum, bool& isEmpty, int T) {
	if (T == A.size()) {
		if (!isEmpty && sum == S) cnt++;
		return;
	}

	dfs(A, S, cnt, sum, isEmpty, T+1);

	sum += A[T];
	bool prev = isEmpty;
	isEmpty = false;
	dfs(A, S, cnt, sum, isEmpty, T+1);
	isEmpty = prev;
	sum -= A[T];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;
	vector<int> A(N);
	for (int i=0; i<N; ++i) cin >> A[i];

	int cnt = 0;
	int sum = 0;
	bool isEmpty = true;
	dfs(A, S, cnt, sum, isEmpty, 0);
	cout << cnt << '\n';
	return 0;
}