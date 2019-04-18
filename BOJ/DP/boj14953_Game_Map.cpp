#include <stdio.h>

struct Pair {
	int val, idx;
	Pair() { val = idx = 0; }
	~Pair() {}
};

class Vector {
private:
	int _size, _capacity;
	int *arr;
public:
	Vector() {
		_size = 0, _capacity = 8;
		arr = new int[_capacity];
	}
	~Vector() { delete []arr; }

	void push_back(int num) {
		if (_size >= _capacity) {
			_capacity *= 2;
			int *tmp = new int[_capacity];
			for (int i = 0; i < _size; ++i) tmp[i] = arr[i];
			delete []arr;
			arr = tmp;
		}
		arr[_size++] = num;
	}

	int size() {
		return _size;
	}

	int get(int index) {
		if (index < 0 || index >= _size) throw index;
		return arr[index];
	}
};

class MinHeap {
private:
	int _size;
	Pair **tree;
	void percolate_up(int index) {
		if (index == 0) return;
		int parent = (index - 1) / 2;
		if (tree[index]->val < tree[parent]->val) {
			Pair *tmp = tree[parent];
			tree[parent] = tree[index];
			tree[index] = tmp;
			percolate_up(parent);
		}
	}
	void percolate_down(int index) {
		if (2 * index + 1 >= _size) return;
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		if (right >= _size || tree[left]->val < tree[right]->val) {
			if (tree[left]->val < tree[index]->val) {
				Pair *tmp = tree[left];
				tree[left] = tree[index];
				tree[index] = tmp;
				percolate_down(left);
			}
		} else if (right < _size) {
			if (tree[right]->val < tree[index]->val) {
				Pair *tmp = tree[right];
				tree[right] = tree[index];
				tree[index] = tmp;
				percolate_down(right);
			}
		}
	}
public:
	MinHeap() {
		_size = 0;
		tree = new Pair*[100000];
	}
	~MinHeap() {
		for (int i = 0; i < 100000; ++i) delete tree[i];
		delete tree;
	}
	void insert(Pair *p) {
		tree[_size++] = p;
		percolate_up(_size - 1);
	}
	Pair* get_min() {
		Pair* ret = tree[0];
		tree[0] = tree[--_size];
		percolate_down(0);
		return ret;
	}
	int size() { return _size; }
};

int max(int a, int b) { return a > b ? a : b; }

const int MAX = 1e5;
int N, M, mx = 1, DP[MAX];
Vector* edges[MAX];
MinHeap* heap;

int main(int argc, char *argv[]) {
	scanf("%d %d", &N, &M);
	for (int i = 0, u, v; i < M; ++i) {
		scanf("%d %d", &u, &v);
		if (!edges[u]) edges[u] = new Vector;
		if (!edges[v]) edges[v] = new Vector;
		edges[u]->push_back(v);
		edges[v]->push_back(u);
	}

	heap = new MinHeap;
	for (int i = 0; i < N; ++i) {
		if (edges[i]) {
			Pair *p = new Pair;
			p->val = edges[i]->size();
			p->idx = i;
			heap->insert(p);
		}
	}

	while (heap->size() > 0) {
		Pair* cur = heap->get_min();
		int len = edges[cur->idx]->size(), _mx = 0;
		for (int i = 0; i < len; ++i) {
			int next = edges[cur->idx]->get(i);
			if (cur->val > edges[next]->size()) 
				_mx = max(_mx, DP[next]);
		}
		DP[cur->idx] = _mx + 1;
		mx = max(mx, DP[cur->idx]);
		delete cur;
	}

	printf("%d\n", mx);
	for (int i = 0; i < MAX; ++i) if (edges[i]) delete edges[i];
	return 0;
}