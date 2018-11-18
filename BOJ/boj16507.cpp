#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end) {
	if (start == end) 
		return tree[node] = arr[start];

	int mid = (start + end)/2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid+1, end);
}

int sum(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) 
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start+end)/2;
	return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int R, C, Q;
	vector< vector<int> > A;
	int r1, c1, r2, c2;

	cin >> R >> C >> Q;
	A.resize(R);
	for (int i=0; i<R; i++) {
		A[i].resize(C);
		for (int j=0; j<C; j++) {
			cin >> A[i][j];
		}
	}

	int h = (int)ceil(log2(C));
	int tree_size = (1 << (h+1));

	vector< vector<int> > tree(R);
	for (int i=0; i<R; i++) {
		tree[i].resize(tree_size);
		init(A[i], tree[i], 1, 0, C-1);
	}

	while (Q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		int SUM = 0;
		for (int i=r1-1; i<r2; i++) {
			SUM += sum(tree[i], 1, 0, C-1, c1-1, c2-1);
		}
		cout << (SUM / ((r2 - r1 + 1) * (c2 - c1 + 1))) << '\n'; 
	}

	return 0;
}