#include <stdio.h>

template <typename T>
class Queue {
public:
	Queue(int c = 2500) {
		_head = _tail = 0;
		_capacity = c;
		_data = new T[_capacity];
	}
	~Queue() { delete []_data; }
	bool empty() { return _head == _tail; }
	int size() { return (_tail - _head + _capacity) % _capacity; }
	T front() { return _data[(_head + 1) % _capacity]; }
	T back() { return _data[_tail]; }
	void push(T item) {
		if ((_tail + 1) % _capacity == _head) {
			_capacity *= 2;
			T* tmp = new T[_capacity];
			int new_head = 0, new_tail = 0, prev_capacity = _capacity / 2;
			while (_tail != _head) {
				_head = (_head + 1) % prev_capacity;
				tmp[++new_tail] = _data[_head];
			}
			_head = new_head, _tail = new_tail;
			delete []_data;
			_data = tmp;
		}
		_tail = (_tail + 1) % _capacity;
		_data[_tail] = item;
	}
	void pop() { _head = (_head + 1) % _capacity; }
private:
	T* _data;
	int _head, _tail, _capacity;
};

struct pair {
	int r, c;
	pair(): r(0), c(0){}
	pair(int _r, int _c): r(_r), c(_c){}
};

const int MAX = 50;
const int move_r[] = {0, -1, 0, 1};
const int move_c[] = {-1, 0, 1, 0};
int N, M, G, MAP[MAX][MAX], group[MAX][MAX], cnt[MAX * MAX + 1];

template <typename T>
T max(T a, T b) { return a > b ? a : b; }

int main(int argc, char *argv[]) {
	Queue <pair> q;
	
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) scanf("%d", MAP[i] + j);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!group[i][j]) {
				++G;
				q.push(pair(i, j));
				group[i][j] = G; 
				while (!q.empty()) {
					pair cur = q.front();
					q.pop();
					cnt[G]++;

					for (int k = 0; k < 4; ++k) {
						if (MAP[cur.r][cur.c] & (1 << k)) continue;
						int dr = cur.r + move_r[k];
						int dc = cur.c + move_c[k];
						if (dr < 0 || dr >= N || dc < 0 || dc >= M || group[dr][dc]) continue;
						q.push(pair(dr, dc));
						group[dr][dc] = G;
					}
				}
			}
		}
	}

	int ans[3] = {G};
	for (int i = 1; i <= G; ++i) ans[1] = max(ans[1], cnt[i]);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (MAP[i][j] & (1 << k)) {
					int dr = i + move_r[k];
					int dc = j + move_c[k];
					if (dr < 0 || dr >= N || dc < 0 || dc >= M) continue;
					if (group[i][j] != group[dr][dc]) ans[2] = max(ans[2], cnt[group[i][j]] + cnt[group[dr][dc]]);
				}
			}
		}
	}

	for (int i = 0; i < 3; ++i) printf("%d\n", ans[i]);
	return 0;
}