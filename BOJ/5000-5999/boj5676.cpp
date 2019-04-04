#include <iostream>
#include <vector>
using namespace std;

void update(vector<int>& tree, int node, int diff) {
	while (node < tree.size()) {
		tree[node] += diff;
		node += (node & -node);
	}
}

int sum(vector<int>& tree, int node) {
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

	int N, K, l, r;
	char c;
	vector<int> A, zero, minus;
	vector<char> result;

	while ( cin >> N >> K ) {
		A.resize(N+1, 0); zero.resize(N+1, 0); minus.resize(N+1, 0);
		result.clear();
		for (int i=1; i<=N; ++i) {
			cin >> A[i];
			zero[i] = 0;
			minus[i] = 0;
		}

		for (int i=1; i<=N; ++i) {
			if (A[i] == 0) update(zero, i, 1);
			else if (A[i] < 0) update(minus, i, 1);
		}

		for (int i=0; i<K; ++i) {
			cin >> c >> l >> r;
			if (c == 'C') {
				if (A[l] == 0) {
					if (r != 0) {
						update(zero, l, -1);
						if (r < 0) update(minus, l, 1);
					}
				} else if (A[l] < 0) {
					if (r >= 0) {
						update(minus, l, -1);
						if (r == 0) update(zero, l, 1);	
					}
				} else {
					if (r < 0) update(minus, l, 1);
					else if (r == 0) update(zero, l, 1);
				}
				A[l] = r;
			} else {
				int zeros = (sum(zero, r) - sum(zero, l-1));
				if (zeros) result.push_back('0');
				else {
					int cnt = (sum(minus, r) - sum(minus, l-1));
					if (cnt % 2) result.push_back('-');
					else result.push_back('+');
				}
			}
		}
		for (auto &it : result) {
			cout << it;
		}
		cout << '\n';
	}

	return 0;
}