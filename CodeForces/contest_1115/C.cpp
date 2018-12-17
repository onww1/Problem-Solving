#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define MOD 1000000007
using namespace std;

int init(char *arr, vector<int> &tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = (arr[start] == '1' ? 1 : 0);

	int mid = (start + end) / 2;

	return tree[node] = init(arr, tree, node * 2, start, mid) + 
						init(arr, tree, node * 2 + 1, mid + 1, end);
}

int sum(vector<int> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end)/2;
	return sum(tree, node * 2, start, mid, left, right) +
			sum(tree, node * 2 + 1, mid+1, end, left, right);
}

int main() {
	int N, Q;
	char D[100001];

	scanf("%d %d", &N, &Q);
	scanf("%s", D);

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h+1));
	vector<int> tree(tree_size);

	init(D, tree, 1, 0, N-1);

	int left, right;
	while (Q--) {
		scanf("%d %d", &left, &right);
		int numOfOne = sum(tree, 1, 0, N-1, left-1, right-1);
		if (numOfOne == 0) {
			cout << 0 << '\n';
			continue;
		}

		int len = right - left + 1;
		long long sum = 1;
		for (int i=numOfOne; i > 0;) {
			sum = (i >= 25 ? sum << 25 : sum << i)%MOD;
			if ( i >= 25 ) i -= 25;
			else i = 0;
		}
		sum -= 1LL;
		for (int i=len - numOfOne; i>0;) {
			sum = (i >= 25 ? sum << 25 : sum << i)%MOD;
			if ( i >= 25 ) i -= 25;
			else i = 0;
		}

		cout << sum << '\n';
	}

	return 0;
}