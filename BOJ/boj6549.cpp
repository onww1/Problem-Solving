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

	return tree[node] = min ( init(arr, tree, node * 2, start, mid) ,
							  init(arr, tree, node * 2 + 1 , mid + 1, end) ); 
}

int getMin( std::vector<int> &tree, int node, int start, int end, int left, int right ){
	if( end < left || right < start ) return 1e9;
	if( left <= start && end <= right ) return tree[node];

	int mid = ( start + end ) / 2;

	return min( getMin( tree, node * 2, start, mid, left, right ) ,
				getMin( tree, node * 2 + 1, mid + 1, end, left, right ) );
}

int main(void){
	int n, in;
	long area, max;
	while(1){
		scanf("%d", &n);
		if(!n) break;
		max = 0l;

		int height = (int)ceil(log2(n));
		int tree_size = (1 << (height+1));

		std::vector<int> h(n);
		std::vector<int> tree(tree_size);

		for(int i=0; i<n; i++){
			scanf("%d", &in);
			h[i] = in;
		}

		init( h, tree, 1, 0, n-1 );

		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				area = (long)getMin(tree, 1, 0, n-1, i, j) * (long)(j - i + 1);
				if( area > max ) max = area;
			}
		}

		printf("%ld\n", max);
	}	

	return 0;
}