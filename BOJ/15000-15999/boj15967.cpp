#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end)
{
	if(start == end){
		return tree[node] = a[start];
	} else {
		return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
	}
}

void update_lazy(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end)
{
	if(lazy[node] != 0){
		tree[node] += (end-start+1)*lazy[node];
		if(start != end)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right, long long diff)
{
	update_lazy(tree, lazy, node, start, end);
	if(left > end || right < start){
		return;
	}
	if(left <= start && end <= right){
		tree[node] += (end-start+1)*diff;
		if(start != end){
			lazy[node*2] += diff;
			lazy[node*2+1] += diff;
		}
		return;
	}
	update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
	update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
	tree[node] = tree[node*2] + tree[node*2+1];
}

long long sum(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);
	if(left > end || right < start){
		return 0;
	}
	if(left <= start && end <= right){
		return tree[node];
	}
	return sum(tree, lazy, node*2, start, (start+end)/2, left, right) + sum(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}

int main(void)
{
	int n, q1, q2;
	scanf("%d %d %d", &n, &q1, &q2);
	vector<long long> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h+1)) - 1;
	vector<long long> tree(tree_size);
	vector<long long> lazy(tree_size);

	for(int i=0; i<n; i++)
		scanf("%lld", &a[i]);

	init(a, tree, 1, 0, n-1);

	q1 += q2;
	int q,w,e;
	long long r;
	for(int i=0; i<q1; i++)
	{
		scanf("%d", &q);
		if(q == 1)
		{
			scanf("%d %d", &w, &e);
			printf("%lld\n", sum(tree, lazy, 1, 0, n-1, w-1, e-1));
		}
		else
		{
			scanf("%d %d %lld", &w, &e, &r);
			update_range(tree, lazy, 1, 0, n-1, w-1, e-1, r);
		}
	}

	return 0;
}