#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[8];
bool visited[8] = {false, };
vector<int> vec;

void dfs(int t) {
	if (t == M) {
		cout << vec[0];
		for (int i=1; i<vec.size(); i++) {
			cout << ' ' << vec[i];
		}
		cout << '\n';
		return;
	}

	int prev = -1;
	for (int i=0; i<N; i++) {
		if (visited[i]) continue;
		if (prev == -1 || prev != A[i]) {
			visited[i] = true;
			vec.push_back(A[i]);
			dfs(t + 1);
			vec.pop_back();
			visited[i] = false;
			prev = A[i];
		}
	}
}

int main() {	
	cin >> N >> M;
	for (int i=0; i<N; i++)
		cin >> A[i];

	sort(A, A+N);

	dfs(0);

	return 0;
}