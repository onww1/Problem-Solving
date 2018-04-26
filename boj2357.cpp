#include <cstdio>
#include <cmath>
#include <vector>

int min( int a, int b ){
	return a<b?a:b;
}

int max( int a, int b ){
	return a>b?a:b;
}

int initMax( std::vector<int> &arr, std::vector<int> &tree, int node, int start, int end ){
	if( start == end ) 
		return tree[node] = arr[start];

	int mid = ( start + end ) / 2;

	return tree[node] = max( initMax( arr, tree, node * 2, start, mid),
							 initMax( arr, tree, node * 2 + 1, mid + 1, end) );
}

int initMin( std::vector<int> &arr, std::vector<int> &tree, int node, int start, int end ){
	if( start == end ) 
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = min( initMin( arr, tree, node * 2, start, mid ),
							 initMin( arr, tree, node * 2 + 1, mid + 1, end) );
}

int getMax( std::vector<int> &tree, int node, int start, int end, int left, int right ){
	if( end < left || start > right ) return 0;
	if( left <= start && end <= right ) return tree[node];

	int mid = ( start + end ) / 2;
	return max( getMax( tree, node * 2, start, mid, left, right ),
				getMax( tree, node * 2 + 1, mid + 1, end, left, right) );
}

int getMin( std::vector<int> &tree, int node, int start, int end, int left, int right ){
	if( end < left || start > right ) return 1e9;
	if( left <= start && end <= right ) return tree[node];

	int mid = ( start + end ) / 2;
	return min( getMin( tree, node * 2, start, mid, left, right),
				getMin( tree, node * 2 + 1, mid + 1, end, left, right) );
}

int main(void){
	int n, m, in;
	scanf("%d %d", &n, &m);

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h+1));

	std::vector<int> arr(n+1);
	std::vector<int> treeMax(tree_size);
	std::vector<int> treeMin(tree_size);

	for(int i=0; i<n; i++){
		scanf("%d", &in);
		arr[i] = in;
	}

	initMax( arr, treeMax, 1, 0, n-1 );
	initMin( arr, treeMin, 1, 0, n-1 );

	int a, b;
	while(m--){
		scanf("%d %d", &a, &b);
		printf("%d %d\n", getMin(treeMin, 1, 0, n-1, a-1, b-1), getMax(treeMax, 1, 0, n-1, a-1, b-1));
	}

	return 0;
}