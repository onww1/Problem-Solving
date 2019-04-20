#include <stdio.h>

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void sort(T *begin, T *end, bool (*cmp)(T&, T&)) {
	if (begin >= end) return;
	T pivot = *begin;
	T *left = begin + 1, *right = end - 1;
	while (left <= right) {
		while (left < end && cmp(*left, pivot)) left++;
		while (right > begin && cmp(pivot, *right)) right--;
		if (left < right) swap(*left, *right);
	}
	swap(*right, *begin);
	sort(begin, right, cmp);
	sort(left, end, cmp);
}

template <typename T>
class Priority_queue {
public:
	Priority_queue() {
		_size = 0;
		_capacity = 1 << 10;
		_data = new T[_capacity];
	}
	~Priority_queue() { }
	void push(T item) {
		if (_size == _capacity) {
			_capacity *= 2;
			T *tmp = new T[_capacity];
			for (int i = 0; i < _size; ++i) tmp[i] = _data[i];
			_data = tmp;
		}
		_data[_size++] = item;
		percolate_up(_size - 1);
	}
	void pop() {
		_data[0] = _data[--_size];
		percolate_down(0);
	}
	T top() { return _data[0]; }
	int size() { return _size; }
	bool empty() { return _size == 0; }
private:
	int _size, _capacity;
	T *_data;
	void percolate_up(int index) {
		if (index == 0) return;
		int parent = (index - 1) >> 1;
		if (_data[index] < _data[parent]) {
			swap(_data[index], _data[parent]);
			percolate_up(parent);
		}
	}
	void percolate_down(int index) {
		if (index * 2 + 1 >= _size) return;
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		if (right >= _size || _data[left] < _data[right]) {
			if (_data[left] < _data[index]) {
				swap(_data[left], _data[index]);
				percolate_down(left);
			}
		} else if (right < _size) {
			if (_data[right] < _data[index]) {
				swap(_data[right], _data[index]);
				percolate_down(right);
			}
		}
	}
};

struct Pair {
	int p, d;
	Pair() { p = d = 0; }
	Pair(int _p, int _d): p(_p), d(_d){};
	~Pair() {}
	bool operator< (const Pair& other) const {
		if (p == other.p) return d > other.d;
		return p > other.p;
	}
};

bool cmp(Pair &a, Pair &b) {
	if (a.d == b.d) return a.p >= b.p;
	return a.d > b.d;
}

const int MAX = 1e4;
int N, ans;
Pair A[MAX];

int main(int argc, char *argv[]) {
	Priority_queue <Pair> pq;

	scanf("%d", &N);
	for (int i = 0, p, d; i < N; ++i) {
		scanf("%d %d", &p, &d);
		A[i] = Pair(p, d);
	}

	sort(A, A + N, cmp);

	for (int i = 0, days = MAX; days > 0; ) {
		while (i < N && A[i].d >= days) pq.push(A[i++]);
		if (!pq.empty()) {
			ans += pq.top().p;
			pq.pop();
			days--;
		} 
		else if (i < N) days = A[i].d;
		else break;
	}

	printf("%d\n", ans);
	return 0;
}