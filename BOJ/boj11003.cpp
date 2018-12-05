#include <iostream>
#include <vector>
#include <cmath>
#define INF 2'000'000'000;
using namespace std;

int getMin(int a, int b) { return a < b ? a : b; }

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end) {
	if (start == end) 
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = getMin(init(arr, tree, node * 2, start, mid),
							   init(arr, tree, node * 2 + 1, mid+1, end));
}

int sum(vector<int>& tree, int node, int start, int end, int left, int right) {
	if ( left > end || right < start ) return INF;

	if ( left <= start && end <= right ) return tree[node];

	int mid = (start + end)/2;
	return getMin( sum(tree, node*2, start, mid, left, right),
				   sum(tree, node*2+1, mid+1, end, left, right));
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h+1));

	vector<int> arr(N);
	vector<int> tree(tree_size);

	for (int i=0; i<N; i++) cin >> arr[i];

	init(arr, tree, 1, 0, N-1);
	for (int i=0; i<N; i++) {
		cout << sum(tree, 1, 0, N-1, i - L + 1 < 0 ? 0 : i - L + 1, i) << ' ';
	}
	cout << '\n';

	return 0;
}