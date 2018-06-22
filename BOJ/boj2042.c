#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long init(long long* arr, long long* tree, int node, int start, int end){
	if(start == end){
		return tree[node] = arr[start];
	} else {
		return tree[node] = init(arr, tree, node*2, start, (start+end)/2)
						  + init(arr, tree, node*2 + 1, (start+end)/2 + 1, end);
	}
}

long long sum(long long* tree, int node, int start, int end, int left, int right){
	if(left > end || right < start){
		return 0;
	}
	if(left <= start && end <= right){
		return tree[node];
	}
	return sum(tree, node*2, start, (start+end)/2, left, right) +
		   sum(tree, node*2+1, (start+end)/2 + 1, end, left, right);
}

void update(long long* tree, int node, int start, int end, int index, long long diff){
	if(index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if(start != end) {
		update(tree, node*2, start, (start+end)/2, index, diff);
		update(tree, node*2+1, (start+end)/2+1, end, index, diff);
	}
}

int main(void){
	int n, m, k;
	long long *arr, *tree, elem;
	scanf("%d %d %d", &n, &m, &k);

	arr  = (long long*)malloc(sizeof(long long) * n);
	tree = (long long*)malloc(sizeof(long long) * (int)pow(2.0, ceil(log((double)n)/log(2.0))+1));

	for(int i=0; i<n; i++){
		scanf("%lld", &elem);
		arr[i] = elem;
	}

	init(arr, tree, 1, 0, n-1);

	int len = m+k;
	for(int i=0; i<len; i++){
		int t1;
		scanf("%d", &t1);
		if(t1 == 1){
			int t2;
			long long t3;
			scanf("%d %lld", &t2, &t3);
			t2 -= 1;
			long long diff = t3 - arr[t2];
			arr[t2] = t3;
			update(tree, 1, 0, n-1, t2, diff);
		} else if(t1 == 2){
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%lld\n", sum(tree, 1, 0, n-1, t2-1, t3-1));
		}
	}

	free(arr);
	free(tree);
	return 0;
}