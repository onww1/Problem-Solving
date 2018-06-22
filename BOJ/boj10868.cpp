#include <cstdio>
#include <cmath>
#include <vector>

int min(int a, int b){
	return a<b?a:b;
}

int init( std::vector<int> &arr, std::vector<int> &tree, int node, int start, int end ){
	if( start == end )
		return tree[node] = arr[start];

	int mid = ( start + end ) / 2;

	return tree[node] = min(init( arr, tree, node * 2, start, mid )
					  	  , init( arr, tree, node * 2 + 1, mid + 1, end ));
}

int sum( std::vector<int> &tree, int node, int start, int end, int left, int right ){
	if( left>end || right<start ) return 1e9;
	if( left <= start && end <= right ) return tree[node];

	int mid = ( start + end ) / 2;
	return min(sum( tree, node * 2, start, mid, left, right )
	     	 , sum( tree, node * 2 + 1, mid + 1, end, left, right ));
}

int main(void){	
	int n, m, in;
	scanf("%d %d", &n, &m);

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h+1));

	std::vector<int> arr(n+1);
	std::vector<int> tree(tree_size);

	for(int i=0; i<n; i++){
		scanf("%d", &in);
		arr[i] = in;
	}

	init( arr, tree, 1, 0, n-1 );
	
	int a, b;
	while(m--){
		scanf("%d %d", &a, &b);
		printf("%d\n", sum(tree, 1, 0, n-1, a-1, b-1));
	}

	return 0;
}