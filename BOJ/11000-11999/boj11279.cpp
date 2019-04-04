#include <iostream>
#define INF 987654321
using namespace std;

int heap[100000];
int size = 0;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void percolateUp(int pos) {
	if (pos <= 0) return;
	int parent = (pos - 1)/2;
	if (heap[parent] < heap[pos]) {
		swap(heap[parent], heap[pos]);
		percolateUp(parent);
	}
}

void percolateDown(int pos) {
	int left, right, max;
	left = 2*pos + 1 < size ? heap[2*pos + 1] : -INF;
	right = 2*pos + 2 < size ? heap[2*pos + 2] : -INF;
	if (left < 0 && right < 0) return;
	max = left > right ? 2*pos + 1 : 2*pos + 2;
	if (heap[pos] < heap[max]) { 
		swap(heap[pos], heap[max]);
		percolateDown(max);
	}
}

void push(int n) {
	if (size == 100000) 
		return;

	heap[size] = n;
	size++;
	percolateUp(size-1);
}

int pop() {
	if (size == 0) return 0;

	int data = heap[0];
	heap[0] = heap[size-1];
	heap[size-1] = 0;
	size--;
	percolateDown(0);
	return data;
}

void printHeap() {
	for (int i=0; i<size; i++) {
		cout << heap[i] << ' ';
	}
	cout << '\n';
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, x;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> x;
		if (!x) {
			cout << pop() << '\n';
		}
		else {
			push(x);
		}
		// printHeap();
	}

	return 0;
}