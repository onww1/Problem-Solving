#include <iostream>
#include <vector>
using namespace std;

void update(vector<int>& tree, int node, int diff) {
	while (node < tree.size()) {
		tree[node] += diff;
		node += (node & -node);
	}
}

int sum(vector<int> &tree, int node) {
	int answer = 0;
	while (node > 0) {
		answer += tree[node];
		node -= (node & -node);
	}
	return answer;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	vector<int> tree(200001), idx(100001);
	int N, M, cnt = 0, in;

	while (T--) {
		cin >> N >> M;
		for (int i=1; i<=N+M; ++i) tree[i] = 0;
		for (int i=1; i<=N; ++i) {
			update(tree, i, 1);
			idx[i] = N-i+1;
		}

		for (int i=1; i<=M; ++i) {
			cin >> in;
			cout << (N - sum(tree, idx[in])) << ' ';

			update(tree, idx[in], -1);
			idx[in] = N + i;
			update(tree, idx[in], 1);
		}
		cout << '\n';
	}

	return 0;
}